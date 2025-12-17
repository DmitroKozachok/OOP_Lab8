#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "playlist.h"
#include "player.h"
#include "track.h"
#include "localtrack.h"
#include "streamtrack.h"

#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QFileInfo>
#include <QUrl>
#include <QHeaderView>
#include <QTableWidget>
#include <QSlider>
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_player(new Player(this))
{
    ui->setupUi(this);

    ui->playlistTable->setColumnCount(2);
    {
        QStringList headers;
        headers << tr("Playlist") << tr("Tracks");
        ui->playlistTable->setHorizontalHeaderLabels(headers);
    }
    ui->playlistTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->playlistTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->playlistTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->playlistTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->playlistTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->playlistTracksTable->setColumnCount(3);
    {
        QStringList headers;
        headers << tr("Title") << tr("Artist") << tr("Duration");
        ui->playlistTracksTable->setHorizontalHeaderLabels(headers);
    }
    ui->playlistTracksTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->playlistTracksTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->playlistTracksTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->playlistTracksTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->playlistTracksTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->playlistTracksTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->onlineTracksTable->setColumnCount(3);
    {
        QStringList headers;
        headers << tr("Title") << tr("Artist") << tr("Duration");
        ui->onlineTracksTable->setHorizontalHeaderLabels(headers);
    }
    ui->onlineTracksTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->onlineTracksTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->onlineTracksTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->onlineTracksTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->onlineTracksTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->onlineTracksTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->volumeSlider->setRange(0, 100);
    ui->volumeSlider->setValue(50);
    ui->positionSlider->setRange(0, 0);

    ui->positionTimeLabel->setText("00:00 / 00:00");

    ui->volumeLabel->setText(tr("Volume: %1%").arg(ui->volumeSlider->value()));

    connect(ui->playlistTable, &QTableWidget::currentCellChanged,
            this, [this](int currentRow, int, int, int){
                onPlaylistSelectionChanged(currentRow);
            });

    connect(ui->playlistTracksTable, &QTableWidget::cellDoubleClicked,
            this, &MainWindow::onPlaylistTrackDoubleClicked);

    connect(ui->onlineTracksTable, &QTableWidget::cellDoubleClicked,
            this, &MainWindow::onOnlineTrackDoubleClicked);

    connect(ui->playButton, &QPushButton::clicked,
            this, &MainWindow::onPlayClicked);
    connect(ui->pauseButton, &QPushButton::clicked,
            this, &MainWindow::onPauseClicked);
    connect(ui->nextButton, &QPushButton::clicked,
            this, &MainWindow::onNextClicked);
    connect(ui->prevButton, &QPushButton::clicked,
            this, &MainWindow::onPrevClicked);

    connect(ui->volumeSlider, &QSlider::valueChanged,
            this, &MainWindow::onVolumeSliderChanged);

    connect(ui->positionSlider, &QSlider::sliderPressed, [this]() {
        m_isSeeking = true;
    });
    connect(ui->positionSlider, &QSlider::sliderReleased,
            this, &MainWindow::onSeekSliderReleased);

    connect(ui->addPlaylistButton, &QPushButton::clicked,
            this, &MainWindow::onAddPlaylistClicked);
    connect(ui->removePlaylistButton, &QPushButton::clicked,
            this, &MainWindow::onRemovePlaylistClicked);

    connect(ui->addLocalTrackButton, &QPushButton::clicked,
            this, &MainWindow::onAddLocalTrackClicked);
    connect(ui->removeLocalTrackButton, &QPushButton::clicked,
            this, &MainWindow::onRemoveLocalTrackClicked);

    connect(ui->addOnlineTrackButton, &QPushButton::clicked,
            this, &MainWindow::onAddOnlineTrackClicked);
    connect(ui->removeOnlineTrackButton, &QPushButton::clicked,
            this, &MainWindow::onRemoveOnlineTrackClicked);

    connect(m_player, &Player::positionChanged,
            this, &MainWindow::onPlayerPositionChanged);
    connect(m_player, &Player::durationChanged,
            this, &MainWindow::onPlayerDurationChanged);
    connect(m_player, &Player::currentTrackChanged,
            this, &MainWindow::updateCurrentTrackInfo);

    m_onlinePlaylist = std::make_shared<Playlist>(tr("Online Library"));

    refreshPlaylistList();
    refreshTrackTables();

    if (!m_playlists.isEmpty()) {
        ui->playlistTable->setCurrentCell(0, 0);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::formatTime(qint64 ms) const
{
    if (ms < 0)
        ms = 0;
    qint64 totalSeconds = ms / 1000;
    qint64 minutes = totalSeconds / 60;
    qint64 seconds = totalSeconds % 60;
    return QString("%1:%2")
        .arg(minutes)
        .arg(seconds, 2, 10, QChar('0'));
}

void MainWindow::refreshPlaylistList()
{
    ui->playlistTable->setRowCount(m_playlists.size());

    for (int i = 0; i < m_playlists.size(); ++i) {
        auto pl = m_playlists[i];

        auto *nameItem = new QTableWidgetItem(pl->name());
        auto *countItem = new QTableWidgetItem(QString::number(pl->size()));

        ui->playlistTable->setItem(i, 0, nameItem);
        ui->playlistTable->setItem(i, 1, countItem);
    }
}

void MainWindow::refreshTrackTables()
{
    m_playlistTrackIndexMap.clear();
    ui->playlistTracksTable->setRowCount(0);

    int plRow = ui->playlistTable->currentRow();
    if (plRow >= 0 && plRow < m_playlists.size()) {
        Playlist *pl = m_playlists[plRow].get();
        for (int i = 0; i < pl->size(); ++i) {
            auto track = pl->trackAt(i);
            if (!track)
                continue;
            if (track->type() != Track::Type::Local)
                continue;

            int durSec = track->durationSeconds();
            QString durStr;
            if (durSec > 0) {
                int minutes = durSec / 60;
                int seconds = durSec % 60;
                durStr = QString("%1:%2")
                             .arg(minutes)
                             .arg(seconds, 2, 10, QChar('0'));
            }

            int row = ui->playlistTracksTable->rowCount();
            ui->playlistTracksTable->insertRow(row);
            ui->playlistTracksTable->setItem(row, 0, new QTableWidgetItem(track->title()));
            ui->playlistTracksTable->setItem(row, 1, new QTableWidgetItem(track->artist()));
            ui->playlistTracksTable->setItem(row, 2, new QTableWidgetItem(durStr));

            m_playlistTrackIndexMap.append(i);
        }
    }

    m_onlineTrackIndexMap.clear();
    ui->onlineTracksTable->setRowCount(0);

    if (m_onlinePlaylist) {
        for (int i = 0; i < m_onlinePlaylist->size(); ++i) {
            auto track = m_onlinePlaylist->trackAt(i);
            if (!track)
                continue;

            int durSec = track->durationSeconds();
            QString durStr;
            if (durSec > 0) {
                int minutes = durSec / 60;
                int seconds = durSec % 60;
                durStr = QString("%1:%2")
                             .arg(minutes)
                             .arg(seconds, 2, 10, QChar('0'));
            }

            int row = ui->onlineTracksTable->rowCount();
            ui->onlineTracksTable->insertRow(row);
            ui->onlineTracksTable->setItem(row, 0, new QTableWidgetItem(track->title()));
            ui->onlineTracksTable->setItem(row, 1, new QTableWidgetItem(track->artist()));
            ui->onlineTracksTable->setItem(row, 2, new QTableWidgetItem(durStr));

            m_onlineTrackIndexMap.append(i);
        }
    }
}

void MainWindow::onPlaylistSelectionChanged(int row)
{
    if (row < 0 || row >= m_playlists.size()) {
        m_player->setPlaylist(nullptr);
        ui->playlistTracksTable->setRowCount(0);
        return;
    }

    Playlist *pl = m_playlists[row].get();
    m_player->setPlaylist(pl);
    refreshTrackTables();
}

void MainWindow::onAddPlaylistClicked()
{
    bool ok = false;
    QString name = QInputDialog::getText(
        this,
        tr("Новий плейлист"),
        tr("Назва плейлиста:"),
        QLineEdit::Normal,
        tr("New Playlist"),
        &ok);

    if (!ok)
        return;

    name = name.trimmed();
    if (name.isEmpty())
        return;

    auto pl = std::make_shared<Playlist>(name);
    m_playlists.push_back(pl);

    refreshPlaylistList();
    int newIndex = m_playlists.size() - 1;
    ui->playlistTable->setCurrentCell(newIndex, 0);
    refreshTrackTables();
}

void MainWindow::onRemovePlaylistClicked()
{
    int row = ui->playlistTable->currentRow();
    if (row < 0 || row >= m_playlists.size())
        return;

    auto answer = QMessageBox::question(
        this,
        tr("Видалити плейлист"),
        tr("Видалити плейлист \"%1\"?").arg(m_playlists[row]->name()));

    if (answer != QMessageBox::Yes)
        return;

    m_playlists.removeAt(row);
    refreshPlaylistList();

    if (!m_playlists.isEmpty()) {
        int newRow = qMin(row, m_playlists.size() - 1);
        ui->playlistTable->setCurrentCell(newRow, 0);
    } else {
        m_player->setPlaylist(nullptr);
        ui->playlistTracksTable->setRowCount(0);
    }
}

void MainWindow::onPlaylistTrackDoubleClicked(int row, int /*column*/)
{
    if (row < 0 || row >= m_playlistTrackIndexMap.size())
        return;

    int plRow = ui->playlistTable->currentRow();
    if (plRow < 0 || plRow >= m_playlists.size())
        return;

    int indexInPlaylist = m_playlistTrackIndexMap[row];
    Playlist *pl = m_playlists[plRow].get();

    m_player->setPlaylist(pl);
    m_player->playIndex(indexInPlaylist);
}

void MainWindow::onAddLocalTrackClicked()
{
    int plRow = ui->playlistTable->currentRow();
    if (plRow < 0 || plRow >= m_playlists.size()) {
        QMessageBox::warning(this,
                             tr("Нема плейлиста"),
                             tr("Спочатку виберіть або створіть плейлист."));
        return;
    }

    QString filePath = QFileDialog::getOpenFileName(
        this,
        tr("Додати аудіофайл"),
        QString(),
        tr("Audio Files (*.mp3 *.wav *.ogg *.flac);;All Files (*.*)"));

    if (filePath.isEmpty())
        return;

    QFileInfo info(filePath);
    QString title = info.completeBaseName();
    QString artist = tr("Unknown");

    auto track = std::make_shared<LocalTrack>(title, artist, 0, filePath);
    m_playlists[plRow]->addTrack(track);

    refreshPlaylistList();
    refreshTrackTables();
}

void MainWindow::onRemoveLocalTrackClicked()
{
    int plRow = ui->playlistTable->currentRow();
    if (plRow < 0 || plRow >= m_playlists.size())
        return;

    int row = ui->playlistTracksTable->currentRow();
    if (row < 0 || row >= m_playlistTrackIndexMap.size())
        return;

    int indexInPlaylist = m_playlistTrackIndexMap[row];
    m_playlists[plRow]->removeTrack(indexInPlaylist);

    refreshPlaylistList();
    refreshTrackTables();
}

void MainWindow::onOnlineTrackDoubleClicked(int row, int /*column*/)
{
    if (!m_onlinePlaylist)
        return;
    if (row < 0 || row >= m_onlineTrackIndexMap.size())
        return;

    int indexInPlaylist = m_onlineTrackIndexMap[row];
    m_player->setPlaylist(m_onlinePlaylist.get());
    m_player->playIndex(indexInPlaylist);
}

void MainWindow::onAddOnlineTrackClicked()
{
    if (!m_onlinePlaylist) {
        m_onlinePlaylist = std::make_shared<Playlist>(tr("Online Library"));
    }

    bool ok = false;
    QString urlStr = QInputDialog::getText(
        this,
        tr("Новий онлайн трек"),
        tr("URL аудіостріму або онлайн-файлу:"),
        QLineEdit::Normal,
        QString(),
        &ok);

    if (!ok)
        return;

    urlStr = urlStr.trimmed();
    if (urlStr.isEmpty())
        return;

    QUrl url(urlStr);
    if (!url.isValid() || url.scheme().isEmpty()) {
        QMessageBox::warning(this,
                             tr("Некоректний URL"),
                             tr("Введіть коректний URL (http/https)."));
        return;
    }

    QString title = url.fileName();
    if (title.isEmpty())
        title = url.host().isEmpty() ? url.toString() : url.host();

    QString artist = tr("Online");

    auto track = std::make_shared<StreamTrack>(title, artist, 0, url);
    m_onlinePlaylist->addTrack(track);

    refreshTrackTables();
}

void MainWindow::onRemoveOnlineTrackClicked()
{
    if (!m_onlinePlaylist)
        return;

    int row = ui->onlineTracksTable->currentRow();
    if (row < 0 || row >= m_onlineTrackIndexMap.size())
        return;

    int indexInPlaylist = m_onlineTrackIndexMap[row];
    m_onlinePlaylist->removeTrack(indexInPlaylist);

    refreshTrackTables();
}

void MainWindow::onPlayClicked()
{
    m_player->play();
}

void MainWindow::onPauseClicked()
{
    m_player->pause();
}

void MainWindow::onNextClicked()
{
    m_player->next();
}

void MainWindow::onPrevClicked()
{
    m_player->previous();
}

void MainWindow::onPlayerPositionChanged(qint64 pos)
{
    if (!m_isSeeking) {
        ui->positionSlider->setValue(static_cast<int>(pos));
    }
    ui->positionTimeLabel->setText(
        QString("%1 / %2")
            .arg(formatTime(pos))
            .arg(formatTime(m_totalDurationMs))
        );
}

void MainWindow::onPlayerDurationChanged(qint64 dur)
{
    m_totalDurationMs = dur;
    ui->positionSlider->setMaximum(static_cast<int>(dur));
    ui->positionTimeLabel->setText(
        QString("%1 / %2")
            .arg(formatTime(ui->positionSlider->value()))
            .arg(formatTime(m_totalDurationMs))
        );
}

void MainWindow::onVolumeSliderChanged(int value)
{
    m_player->setVolume(value);
    ui->volumeLabel->setText(tr("Volume: %1%").arg(value));
}

void MainWindow::onSeekSliderReleased()
{
    m_isSeeking = false;
    qint64 newPos = ui->positionSlider->value();
    m_player->setPosition(newPos);
    ui->positionTimeLabel->setText(
        QString("%1 / %2")
            .arg(formatTime(newPos))
            .arg(formatTime(m_totalDurationMs))
        );
}

void MainWindow::updateCurrentTrackInfo(Track *track)
{
    if (!track) {
        ui->currentTrackLabel->setText(tr("No track"));
        return;
    }
    ui->currentTrackLabel->setText(track->displayInfo());
}
