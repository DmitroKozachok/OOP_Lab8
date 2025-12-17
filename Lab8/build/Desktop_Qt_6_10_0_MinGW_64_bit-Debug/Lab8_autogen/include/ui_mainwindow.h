/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *topLayout;
    QGroupBox *playlistsGroupBox;
    QVBoxLayout *playlistsLayout;
    QTableWidget *playlistTable;
    QHBoxLayout *playlistButtonsLayout;
    QSpacerItem *playlistButtonsSpacer;
    QPushButton *addPlaylistButton;
    QPushButton *removePlaylistButton;
    QGroupBox *libraryGroupBox;
    QVBoxLayout *libraryLayout;
    QTabWidget *libraryTabs;
    QWidget *tabPlaylistTracks;
    QVBoxLayout *playlistTracksLayout;
    QLabel *playlistTracksLabel;
    QTableWidget *playlistTracksTable;
    QHBoxLayout *playlistTracksButtonsLayout;
    QSpacerItem *playlistTracksButtonsSpacer;
    QPushButton *addLocalTrackButton;
    QPushButton *removeLocalTrackButton;
    QWidget *tabOnlineTracks;
    QVBoxLayout *onlineLayout;
    QLabel *onlineLabel;
    QTableWidget *onlineTracksTable;
    QHBoxLayout *onlineButtonsLayout;
    QSpacerItem *onlineButtonsSpacer;
    QPushButton *addOnlineTrackButton;
    QPushButton *removeOnlineTrackButton;
    QFrame *line;
    QGroupBox *nowPlayingGroupBox;
    QVBoxLayout *bottomLayout;
    QLabel *currentTrackLabel;
    QHBoxLayout *controlsLayout;
    QPushButton *prevButton;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *nextButton;
    QVBoxLayout *positionLayout;
    QSlider *positionSlider;
    QLabel *positionTimeLabel;
    QVBoxLayout *volumeLayout;
    QSlider *volumeSlider;
    QLabel *volumeLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 650);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("\n"
"QWidget#centralwidget {\n"
"    background-color: #20232a;\n"
"    color: #f0f0f0;\n"
"    font-family: Segoe UI, Arial;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QGroupBox {\n"
"    border: 1px solid #3c4048;\n"
"    border-radius: 6px;\n"
"    margin-top: 18px;\n"
"    padding-top: 10px;\n"
"    background-color: #242730;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 4px;\n"
"    color: #61dafb;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid #3c4048;\n"
"    border-radius: 6px;\n"
"    background-color: #242730;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background: #2b2f3a;\n"
"    color: #f0f0f0;\n"
"    border: 1px solid #3c4048;\n"
"    padding: 4px 10px;\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    margin-right: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: #3c4048;\n"
"}\n"
"\n"
"QTableWidget {\n"
"    background-color: #282c34;\n"
"    gridline-color: #3c4048;\n"
"    select"
                        "ion-background-color: #3fa7d6;\n"
"    selection-color: #ffffff;\n"
"    alternate-background-color: #323640;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #3c4048;\n"
"    color: #f0f0f0;\n"
"    padding: 4px;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #3fa7d6;\n"
"    color: white;\n"
"    border-radius: 4px;\n"
"    padding: 4px 10px;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4fb7e6;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2f97c6;\n"
"}\n"
"\n"
"QPushButton#playButton {\n"
"    background-color: #4caf50;\n"
"}\n"
"\n"
"QPushButton#playButton:hover {\n"
"    background-color: #5ecf63;\n"
"}\n"
"\n"
"QPushButton#pauseButton {\n"
"    background-color: #ffb300;\n"
"}\n"
"\n"
"QPushButton#pauseButton:hover {\n"
"    background-color: #ffca28;\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    height: 6px;\n"
"    background: #3c4048;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::handle:ho"
                        "rizontal {\n"
"    background: #61dafb;\n"
"    width: 14px;\n"
"    margin: -5px 0;\n"
"    border-radius: 7px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: #3fa7d6;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #f0f0f0;\n"
"}\n"
"\n"
"QLabel#currentTrackLabel {\n"
"    font-weight: bold;\n"
"}\n"
"    "));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        topLayout = new QHBoxLayout();
        topLayout->setObjectName("topLayout");
        playlistsGroupBox = new QGroupBox(centralwidget);
        playlistsGroupBox->setObjectName("playlistsGroupBox");
        playlistsLayout = new QVBoxLayout(playlistsGroupBox);
        playlistsLayout->setObjectName("playlistsLayout");
        playlistTable = new QTableWidget(playlistsGroupBox);
        if (playlistTable->columnCount() < 2)
            playlistTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        playlistTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        playlistTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        playlistTable->setObjectName("playlistTable");
        playlistTable->setColumnCount(2);

        playlistsLayout->addWidget(playlistTable);

        playlistButtonsLayout = new QHBoxLayout();
        playlistButtonsLayout->setObjectName("playlistButtonsLayout");
        playlistButtonsSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        playlistButtonsLayout->addItem(playlistButtonsSpacer);

        addPlaylistButton = new QPushButton(playlistsGroupBox);
        addPlaylistButton->setObjectName("addPlaylistButton");

        playlistButtonsLayout->addWidget(addPlaylistButton);

        removePlaylistButton = new QPushButton(playlistsGroupBox);
        removePlaylistButton->setObjectName("removePlaylistButton");

        playlistButtonsLayout->addWidget(removePlaylistButton);


        playlistsLayout->addLayout(playlistButtonsLayout);


        topLayout->addWidget(playlistsGroupBox);

        libraryGroupBox = new QGroupBox(centralwidget);
        libraryGroupBox->setObjectName("libraryGroupBox");
        libraryLayout = new QVBoxLayout(libraryGroupBox);
        libraryLayout->setObjectName("libraryLayout");
        libraryTabs = new QTabWidget(libraryGroupBox);
        libraryTabs->setObjectName("libraryTabs");
        libraryTabs->setTabPosition(QTabWidget::TabPosition::North);
        tabPlaylistTracks = new QWidget();
        tabPlaylistTracks->setObjectName("tabPlaylistTracks");
        playlistTracksLayout = new QVBoxLayout(tabPlaylistTracks);
        playlistTracksLayout->setObjectName("playlistTracksLayout");
        playlistTracksLabel = new QLabel(tabPlaylistTracks);
        playlistTracksLabel->setObjectName("playlistTracksLabel");

        playlistTracksLayout->addWidget(playlistTracksLabel);

        playlistTracksTable = new QTableWidget(tabPlaylistTracks);
        if (playlistTracksTable->columnCount() < 3)
            playlistTracksTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        playlistTracksTable->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        playlistTracksTable->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        playlistTracksTable->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        playlistTracksTable->setObjectName("playlistTracksTable");
        playlistTracksTable->setColumnCount(3);

        playlistTracksLayout->addWidget(playlistTracksTable);

        playlistTracksButtonsLayout = new QHBoxLayout();
        playlistTracksButtonsLayout->setObjectName("playlistTracksButtonsLayout");
        playlistTracksButtonsSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        playlistTracksButtonsLayout->addItem(playlistTracksButtonsSpacer);

        addLocalTrackButton = new QPushButton(tabPlaylistTracks);
        addLocalTrackButton->setObjectName("addLocalTrackButton");

        playlistTracksButtonsLayout->addWidget(addLocalTrackButton);

        removeLocalTrackButton = new QPushButton(tabPlaylistTracks);
        removeLocalTrackButton->setObjectName("removeLocalTrackButton");

        playlistTracksButtonsLayout->addWidget(removeLocalTrackButton);


        playlistTracksLayout->addLayout(playlistTracksButtonsLayout);

        libraryTabs->addTab(tabPlaylistTracks, QString());
        tabOnlineTracks = new QWidget();
        tabOnlineTracks->setObjectName("tabOnlineTracks");
        onlineLayout = new QVBoxLayout(tabOnlineTracks);
        onlineLayout->setObjectName("onlineLayout");
        onlineLabel = new QLabel(tabOnlineTracks);
        onlineLabel->setObjectName("onlineLabel");

        onlineLayout->addWidget(onlineLabel);

        onlineTracksTable = new QTableWidget(tabOnlineTracks);
        if (onlineTracksTable->columnCount() < 3)
            onlineTracksTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        onlineTracksTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        onlineTracksTable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        onlineTracksTable->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        onlineTracksTable->setObjectName("onlineTracksTable");
        onlineTracksTable->setColumnCount(3);

        onlineLayout->addWidget(onlineTracksTable);

        onlineButtonsLayout = new QHBoxLayout();
        onlineButtonsLayout->setObjectName("onlineButtonsLayout");
        onlineButtonsSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        onlineButtonsLayout->addItem(onlineButtonsSpacer);

        addOnlineTrackButton = new QPushButton(tabOnlineTracks);
        addOnlineTrackButton->setObjectName("addOnlineTrackButton");

        onlineButtonsLayout->addWidget(addOnlineTrackButton);

        removeOnlineTrackButton = new QPushButton(tabOnlineTracks);
        removeOnlineTrackButton->setObjectName("removeOnlineTrackButton");

        onlineButtonsLayout->addWidget(removeOnlineTrackButton);


        onlineLayout->addLayout(onlineButtonsLayout);

        libraryTabs->addTab(tabOnlineTracks, QString());

        libraryLayout->addWidget(libraryTabs);


        topLayout->addWidget(libraryGroupBox);


        verticalLayout->addLayout(topLayout);

        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line);

        nowPlayingGroupBox = new QGroupBox(centralwidget);
        nowPlayingGroupBox->setObjectName("nowPlayingGroupBox");
        bottomLayout = new QVBoxLayout(nowPlayingGroupBox);
        bottomLayout->setObjectName("bottomLayout");
        currentTrackLabel = new QLabel(nowPlayingGroupBox);
        currentTrackLabel->setObjectName("currentTrackLabel");

        bottomLayout->addWidget(currentTrackLabel);

        controlsLayout = new QHBoxLayout();
        controlsLayout->setObjectName("controlsLayout");
        prevButton = new QPushButton(nowPlayingGroupBox);
        prevButton->setObjectName("prevButton");

        controlsLayout->addWidget(prevButton);

        playButton = new QPushButton(nowPlayingGroupBox);
        playButton->setObjectName("playButton");

        controlsLayout->addWidget(playButton);

        pauseButton = new QPushButton(nowPlayingGroupBox);
        pauseButton->setObjectName("pauseButton");

        controlsLayout->addWidget(pauseButton);

        nextButton = new QPushButton(nowPlayingGroupBox);
        nextButton->setObjectName("nextButton");

        controlsLayout->addWidget(nextButton);

        positionLayout = new QVBoxLayout();
        positionLayout->setObjectName("positionLayout");
        positionSlider = new QSlider(nowPlayingGroupBox);
        positionSlider->setObjectName("positionSlider");
        positionSlider->setOrientation(Qt::Orientation::Horizontal);

        positionLayout->addWidget(positionSlider);

        positionTimeLabel = new QLabel(nowPlayingGroupBox);
        positionTimeLabel->setObjectName("positionTimeLabel");

        positionLayout->addWidget(positionTimeLabel);


        controlsLayout->addLayout(positionLayout);

        volumeLayout = new QVBoxLayout();
        volumeLayout->setObjectName("volumeLayout");
        volumeSlider = new QSlider(nowPlayingGroupBox);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setMaximum(100);
        volumeSlider->setOrientation(Qt::Orientation::Horizontal);

        volumeLayout->addWidget(volumeSlider);

        volumeLabel = new QLabel(nowPlayingGroupBox);
        volumeLabel->setObjectName("volumeLabel");

        volumeLayout->addWidget(volumeLabel);


        controlsLayout->addLayout(volumeLayout);


        bottomLayout->addLayout(controlsLayout);


        verticalLayout->addWidget(nowPlayingGroupBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Music Player", nullptr));
        playlistsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Playlists", nullptr));
        QTableWidgetItem *___qtablewidgetitem = playlistTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Playlist", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = playlistTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Tracks", nullptr));
        addPlaylistButton->setText(QCoreApplication::translate("MainWindow", "Add Playlist", nullptr));
        removePlaylistButton->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        libraryGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Library", nullptr));
        playlistTracksLabel->setText(QCoreApplication::translate("MainWindow", "Tracks in selected playlist", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = playlistTracksTable->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = playlistTracksTable->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Artist", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = playlistTracksTable->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Duration", nullptr));
        addLocalTrackButton->setText(QCoreApplication::translate("MainWindow", "Add Local", nullptr));
        removeLocalTrackButton->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        libraryTabs->setTabText(libraryTabs->indexOf(tabPlaylistTracks), QCoreApplication::translate("MainWindow", "Playlist tracks", nullptr));
        onlineLabel->setText(QCoreApplication::translate("MainWindow", "Online tracks", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = onlineTracksTable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = onlineTracksTable->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Artist", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = onlineTracksTable->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Duration", nullptr));
        addOnlineTrackButton->setText(QCoreApplication::translate("MainWindow", "Add Online", nullptr));
        removeOnlineTrackButton->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        libraryTabs->setTabText(libraryTabs->indexOf(tabOnlineTracks), QCoreApplication::translate("MainWindow", "Online library", nullptr));
        nowPlayingGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Now Playing", nullptr));
        currentTrackLabel->setText(QCoreApplication::translate("MainWindow", "No track", nullptr));
        prevButton->setText(QCoreApplication::translate("MainWindow", "Previous", nullptr));
        playButton->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        nextButton->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        positionTimeLabel->setText(QCoreApplication::translate("MainWindow", "00:00 / 00:00", nullptr));
        volumeLabel->setText(QCoreApplication::translate("MainWindow", "Volume: 50%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
