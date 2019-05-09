#pragma once

#include <QObject>
#include <QImage>
#include <opencv2/opencv.hpp>

class ImageProvider : public QObject {
    Q_OBJECT

public slots:
    void updateImage(const QImage& image, int threshold);

signals:
    void imageReady(const QImage& image);

private:
    QImage convertToQImageCopy(const cv::Mat& mat, const QImage::Format);
    cv::Mat convertToMatCopy(const QImage& img, const int format);

private:
    int m_ratio = 2;
    cv::RNG m_rng = (12345);
};
