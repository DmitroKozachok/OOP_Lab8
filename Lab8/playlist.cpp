#include "playlist.h"

Playlist::Playlist(const QString &name)
    : m_name(name)
{
}

QString Playlist::name() const
{
    return m_name;
}

void Playlist::setName(const QString &name)
{
    m_name = name;
}

void Playlist::addTrack(const std::shared_ptr<Track> &track)
{
    m_tracks.append(track);
}

void Playlist::removeTrack(int index)
{
    if (index >= 0 && index < m_tracks.size())
        m_tracks.removeAt(index);
}

void Playlist::clear()
{
    m_tracks.clear();
}

int Playlist::size() const
{
    return m_tracks.size();
}

std::shared_ptr<Track> Playlist::trackAt(int index) const
{
    if (index < 0 || index >= m_tracks.size())
        return nullptr;
    return m_tracks.at(index);
}

const QVector<std::shared_ptr<Track>> &Playlist::tracks() const
{
    return m_tracks;
}
