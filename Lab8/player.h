#pragma once

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <memory>

#include "playlist.h"

class Track;

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = nullptr);
    ~Player() override;

    void setPlaylist(Playlist *playlist);
    Playlist *playlist() const;

    int currentIndex() const;
    std::shared_ptr<Track> currentTrack() const;

public slots:
    void play();
    void pause();
    void stop();
    void playIndex(int index);
    void next();
    void previous();
    void setVolume(int volume);
    void setPosition(qint64 posMs);

signals:
    void currentTrackChanged(Track *track);
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void stateChanged(QMediaPlayer::PlaybackState state);

private slots:
    void handleMediaStatusChanged(QMediaPlayer::MediaStatus status);

private:
    void applyCurrentTrack();

    Playlist *m_playlist = nullptr;
    int m_currentIndex = -1;

    QMediaPlayer *m_player;
    QAudioOutput *m_audioOutput;
};
