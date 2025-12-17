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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *mainLayout;
    QListWidget *playlistListWidget;
    QTableWidget *tracksTable;
    QVBoxLayout *bottomLayout;
    QLabel *currentTrackLabel;
    QHBoxLayout *controlsLayout;
    QPushButton *prevButton;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *nextButton;
    QSlider *positionSlider;
    QSlider *volumeSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        mainLayout = new QHBoxLayout();
        mainLayout->setObjectName("mainLayout");
        playlistListWidget = new QListWidget(centralwidget);
        playlistListWidget->setObjectName("playlistListWidget");
        playlistListWidget->setMinimumWidth(150);

        mainLayout->addWidget(playlistListWidget);

        tracksTable = new QTableWidget(centralwidget);
        if (tracksTable->columnCount() < 3)
            tracksTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tracksTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tracksTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tracksTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tracksTable->setObjectName("tracksTable");
        tracksTable->setColumnCount(3);

        mainLayout->addWidget(tracksTable);


        verticalLayout->addLayout(mainLayout);

        bottomLayout = new QVBoxLayout();
        bottomLayout->setObjectName("bottomLayout");
        currentTrackLabel = new QLabel(centralwidget);
        currentTrackLabel->setObjectName("currentTrackLabel");

        bottomLayout->addWidget(currentTrackLabel);

        controlsLayout = new QHBoxLayout();
        controlsLayout->setObjectName("controlsLayout");
        prevButton = new QPushButton(centralwidget);
        prevButton->setObjectName("prevButton");

        controlsLayout->addWidget(prevButton);

        playButton = new QPushButton(centralwidget);
        playButton->setObjectName("playButton");

        controlsLayout->addWidget(playButton);

        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName("pauseButton");

        controlsLayout->addWidget(pauseButton);

        nextButton = new QPushButton(centralwidget);
        nextButton->setObjectName("nextButton");

        controlsLayout->addWidget(nextButton);

        positionSlider = new QSlider(centralwidget);
        positionSlider->setObjectName("positionSlider");
        positionSlider->setOrientation(Qt::Horizontal);

        controlsLayout->addWidget(positionSlider);

        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setOrientation(Qt::Horizontal);
        volumeSlider->setMaximum(100);

        controlsLayout->addWidget(volumeSlider);


        bottomLayout->addLayout(controlsLayout);


        verticalLayout->addLayout(bottomLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
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
        QTableWidgetItem *___qtablewidgetitem = tracksTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tracksTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Artist", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tracksTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Duration", nullptr));
        currentTrackLabel->setText(QCoreApplication::translate("MainWindow", "No track", nullptr));
        prevButton->setText(QCoreApplication::translate("MainWindow", "<<", nullptr));
        playButton->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        nextButton->setText(QCoreApplication::translate("MainWindow", ">>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
