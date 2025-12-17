#pragma once

#include "track.h"

class LocalTrack : public Track
{
public:
    LocalTrack(const QString &title,
               const QString &artist,
               int durationSeconds,
               const QString &filePath);

    Type type() const override;
    QUrl mediaUrl() const override;
    QString displayInfo() const override;

    QString filePath() const;
    void setFilePath(const QString &path);

private:
    QString m_filePath;
};
