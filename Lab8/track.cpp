#include "track.h"

Track::Track(const QString &title,
             const QString &artist,
             int durationSeconds)
    : m_title(title),
    m_artist(artist),
    m_durationSeconds(durationSeconds)
{
}

QString Track::title() const
{
    return m_title;
}

void Track::setTitle(const QString &title)
{
    m_title = title;
}

QString Track::artist() const
{
    return m_artist;
}

void Track::setArtist(const QString &artist)
{
    m_artist = artist;
}

int Track::durationSeconds() const
{
    return m_durationSeconds;
}

void Track::setDurationSeconds(int seconds)
{
    m_durationSeconds = seconds;
}

QString Track::displayInfo() const
{
    int minutes = m_durationSeconds / 60;
    int seconds = m_durationSeconds % 60;
    return QString("%1 — %2 (%3:%4)")
        .arg(m_artist,
             m_title,
             QString::number(minutes),
             QString("%1").arg(seconds, 2, 10, QChar('0')));
}
