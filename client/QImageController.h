/************************************************************************
 * This file is part of the minilockcpp distribution
 * (https://github.com/mrom1/minilockcpp).
 * Copyright (c) 2021 mrom1.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 ************************************************************************/



#pragma once

#include <QObject>
#include <QImage>
#include <QThread>

class ImageProvider;

class QImageController :public QObject {
    Q_OBJECT
    Q_PROPERTY(int threshold READ getThreshold WRITE setThreshold NOTIFY thresholdChanged)
    Q_PROPERTY(bool imageLoaded READ getImageLoaded WRITE setImageLoaded NOTIFY imageLoadedChanged())
    Q_PROPERTY(QImage image READ getImage WRITE setImage NOTIFY imageChanged)
    Q_PROPERTY(bool loading READ getLoading NOTIFY loadingChanged)

public:
    explicit QImageController(QObject* parent = nullptr);
    ~QImageController();

    Q_INVOKABLE void loadImage(const QString& file);
    Q_INVOKABLE void clearImage();
    Q_INVOKABLE void resetImage();

public:
    int getThreshold() const;
    void setThreshold(const int threshold);
    bool getImageLoaded() const;
    bool getLoading() const;
    QImage getImage() const;
    void setImageLoaded(const bool isLoaded);
    void setImage(const QImage& image);

public slots:
    void updateImage(const QImage& image);

signals:
    void thresholdChanged();
    void imageLoadedChanged();
    void imageChanged();
    void cannyEdgeDetection(const QImage& image, int threshold);
    void loadingChanged();

private:
    QThread m_thread;
    QImage m_imageOriginal;
    QImage m_image;
    int m_threshold;
    bool m_isImageLoaded = false;
    bool m_isLoading = false;
};
