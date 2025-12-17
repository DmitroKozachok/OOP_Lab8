#include "localtrack.h"

LocalTrack::LocalTrack(const QString &title,
                       const QString &artist,
                       int durationSeconds,
                       const QString &filePath)
    : Track(title, artist, durationSeconds),
    m_filePath(filePath)
{
}

Track::Type LocalTrack::type() const
{
    return Track::Type::Local;
}

QUrl LocalTrack::mediaUrl() const
{
    return QUrl::fromLocalFile(m_filePath);
}

QString LocalTrack::displayInfo() const
{
    return Track::displayInfo() + " [Local]";
}

QString LocalTrack::filePath() const
{
    return m_filePath;
}

void LocalTrack::setFilePath(const QString &path)
{
    m_filePath = path;
}
