#pragma once

#include <QString>
#include <QUrl>

class Track
{
public:
    enum class Type {
        Local,
        Stream
    };

    Track(const QString &title,
          const QString &artist,
          int durationSeconds);
    virtual ~Track() = default;

    QString title() const;
    void setTitle(const QString &title);

    QString artist() const;
    void setArtist(const QString &artist);

    int durationSeconds() const;
    void setDurationSeconds(int seconds);

    virtual Type type() const = 0;
    virtual QUrl mediaUrl() const = 0;

    virtual QString displayInfo() const;

protected:
    QString m_title;
    QString m_artist;
    int m_durationSeconds;
};
