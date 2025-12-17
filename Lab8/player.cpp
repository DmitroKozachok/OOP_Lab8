#include "player.h"
#include "track.h"

#include <algorithm>

Player::Player(QObject *parent)
    : QObject(parent)
{
    m_audioOutput = new QAudioOutput(this);
    m_player = new QMediaPlayer(this);
    m_player->setAudioOutput(m_audioOutput);

    connect(m_player, &QMediaPlayer::positionChanged,
            this, &Player::positionChanged);
    connect(m_player, &QMediaPlayer::durationChanged,
            this, &Player::durationChanged);
    connect(m_player, &QMediaPlayer::playbackStateChanged,
            this, &Player::stateChanged);
    connect(m_player, &QMediaPlayer::mediaStatusChanged,
            this, &Player::handleMediaStatusChanged);
}

Player::~Player() = default;

void Player::setPlaylist(Playlist *playlist)
{
    m_playlist = playlist;
    if (m_playlist && m_playlist->size() > 0) {
        m_currentIndex = 0;
        applyCurrentTrack();
    } else {
        m_currentIndex = -1;
    }
}

Playlist *Player::playlist() const
{
    return m_playlist;
}

int Player::currentIndex() const
{
    return m_currentIndex;
}

std::shared_ptr<Track> Player::currentTrack() const
{
    if (!m_playlist)
        return nullptr;
    return m_playlist->trackAt(m_currentIndex);
}

void Player::play()
{
    if (!m_playlist || m_playlist->size() == 0)
        return;

    if (m_currentIndex < 0)
        m_currentIndex = 0;

    applyCurrentTrack();
    m_player->play();
}

void Player::pause()
{
    m_player->pause();
}

void Player::stop()
{
    m_player->stop();
}

void Player::playIndex(int index)
{
    if (!m_playlist)
        return;
    if (index < 0 || index >= m_playlist->size())
        return;

    m_currentIndex = index;
    applyCurrentTrack();
    m_player->play();
}

void Player::next()
{
    if (!m_playlist || m_playlist->size() == 0)
        return;

    m_currentIndex++;
    if (m_currentIndex >= m_playlist->size())
        m_currentIndex = 0;

    applyCurrentTrack();
    m_player->play();
}

void Player::previous()
{
    if (!m_playlist || m_playlist->size() == 0)
        return;

    m_currentIndex--;
    if (m_currentIndex < 0)
        m_currentIndex = m_playlist->size() - 1;

    applyCurrentTrack();
    m_player->play();
}

void Player::setVolume(int volume)
{
    int clamped = std::clamp(volume, 0, 100);
    qreal v = static_cast<qreal>(clamped) / 100.0;
    m_audioOutput->setVolume(v);
}

void Player::setPosition(qint64 posMs)
{
    m_player->setPosition(posMs);
}

void Player::handleMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia) {
        next();
    }
}

void Player::applyCurrentTrack()
{
    if (!m_playlist)
        return;

    auto track = m_playlist->trackAt(m_currentIndex);
    if (!track)
        return;

    m_player->setSource(track->mediaUrl());
    emit currentTrackChanged(track.get());
}
