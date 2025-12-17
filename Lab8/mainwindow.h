#pragma once

#include <QMainWindow>
#include <QVector>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Playlist;
class Player;
class Track;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void onPlaylistSelectionChanged(int row);
    void onAddPlaylistClicked();
    void onRemovePlaylistClicked();

    void onPlaylistTrackDoubleClicked(int row, int column);
    void onAddLocalTrackClicked();
    void onRemoveLocalTrackClicked();

    void onOnlineTrackDoubleClicked(int row, int column);
    void onAddOnlineTrackClicked();
    void onRemoveOnlineTrackClicked();

    void onPlayClicked();
    void onPauseClicked();
    void onNextClicked();
    void onPrevClicked();

    void onPlayerPositionChanged(qint64 pos);
    void onPlayerDurationChanged(qint64 dur);
    void onVolumeSliderChanged(int value);
    void onSeekSliderReleased();
    void updateCurrentTrackInfo(Track *track);

private:
    void refreshPlaylistList();
    void refreshTrackTables();

    QString formatTime(qint64 ms) const;

    Ui::MainWindow *ui;

    QVector<std::shared_ptr<Playlist>> m_playlists;

    std::shared_ptr<Playlist> m_onlinePlaylist;

    Player *m_player;
    bool m_isSeeking = false;

    qint64 m_totalDurationMs = 0;

    QVector<int> m_playlistTrackIndexMap;
    QVector<int> m_onlineTrackIndexMap;
};
