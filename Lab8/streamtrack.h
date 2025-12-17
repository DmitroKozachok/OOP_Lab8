#pragma once

#include "track.h"

class StreamTrack : public Track
{
public:
    StreamTrack(const QString &title,
                const QString &artist,
                int durationSeconds,
                const QUrl &streamUrl);

    Type type() const override;
    QUrl mediaUrl() const override;
    QString displayInfo() const override;

    QUrl streamUrl() const;
    void setStreamUrl(const QUrl &url);

private:
    QUrl m_streamUrl;
};
