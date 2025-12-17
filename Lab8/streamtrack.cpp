#include "streamtrack.h"

StreamTrack::StreamTrack(const QString &title,
                         const QString &artist,
                         int durationSeconds,
                         const QUrl &streamUrl)
    : Track(title, artist, durationSeconds),
    m_streamUrl(streamUrl)
{
}

Track::Type StreamTrack::type() const
{
    return Track::Type::Stream;
}

QUrl StreamTrack::mediaUrl() const
{
    return m_streamUrl;
}

QString StreamTrack::displayInfo() const
{
    return Track::displayInfo() + " [Stream]";
}

QUrl StreamTrack::streamUrl() const
{
    return m_streamUrl;
}

void StreamTrack::setStreamUrl(const QUrl &url)
{
    m_streamUrl = url;
}
