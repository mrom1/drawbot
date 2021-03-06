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



#include "QImageController.h"
#include "ImageProvider.h"

#include <opencv2/opencv.hpp>
#include <QDebug>
#include <QThread>

QImageController::QImageController(QObject *parent) : QObject(parent)
{
    ImageProvider* provider = new ImageProvider;
    provider->moveToThread(&m_thread);
    connect(&m_thread, &QThread::finished, provider, &QObject::deleteLater);
    connect(this, &QImageController::cannyEdgeDetection, provider, &ImageProvider::updateImage);
    connect(provider, &ImageProvider::imageReady, this, &QImageController::updateImage);
    m_thread.start();
}

QImageController::~QImageController()
{
    m_thread.quit();
    m_thread.wait();
}

void QImageController::loadImage(const QString &file)
{
    m_imageOriginal = QImage(file);
    setImage(m_imageOriginal);
    m_threshold = 0;
    emit thresholdChanged();
    setImageLoaded(true);
}

void QImageController::clearImage() {
    m_imageOriginal = QImage(":/icons/newFile.png");
    m_threshold = 0;
    emit thresholdChanged();
    setImageLoaded(false);
    setImage(m_imageOriginal);
}

void QImageController::resetImage()
{
    m_threshold = 0;
    emit thresholdChanged();
    setImage(m_imageOriginal);
}

int QImageController::getThreshold() const
{
    return m_threshold;
}

void QImageController::setThreshold(const int threshold)
{
    if(m_threshold != threshold && !m_isLoading && m_isImageLoaded) {
        m_threshold = threshold;
        m_isLoading = true;
        emit loadingChanged();
        emit thresholdChanged();
        emit cannyEdgeDetection(m_imageOriginal, m_threshold);
    }
}

bool QImageController::getImageLoaded() const
{
    return m_isImageLoaded;
}

void QImageController::setImageLoaded(const bool isLoaded)
{
    if(m_isImageLoaded != isLoaded) {
        m_isImageLoaded = isLoaded;
        emit imageLoadedChanged();
    }
}

QImage QImageController::getImage() const
{
    return m_image;
}

bool QImageController::getLoading() const
{
    return m_isLoading;
}

void QImageController::setImage(const QImage &image)
{
    if(m_image != image) {
        m_image = image;
        emit imageChanged();
    }
    m_isLoading = false;
}

void QImageController::updateImage(const QImage& image)
{
    setImage(image);
    emit loadingChanged();
}

