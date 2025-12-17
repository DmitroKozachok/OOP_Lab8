#pragma once

#include <QString>
#include <QVector>
#include <memory>

#include "track.h"

class Playlist
{
public:
    explicit Playlist(const QString &name);

    QString name() const;
    void setName(const QString &name);

    void addTrack(const std::shared_ptr<Track> &track);
    void removeTrack(int index);
    void clear();

    int size() const;
    std::shared_ptr<Track> trackAt(int index) const;
    const QVector<std::shared_ptr<Track>> &tracks() const;

private:
    QString m_name;
    QVector<std::shared_ptr<Track>> m_tracks;
};
