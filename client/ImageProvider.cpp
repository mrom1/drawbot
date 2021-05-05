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



#include "ImageProvider.h"

#include <QDebug>
#include <QThread>

QImage ImageProvider::convertToQImageCopy(const cv::Mat &mat, const QImage::Format format)
{
    return QImage(mat.data, mat.cols, mat.rows, format).copy();
}

cv::Mat ImageProvider::convertToMatCopy(const QImage &img, const int format)
{
    return cv::Mat(img.height(), img.width(), format, const_cast<unsigned char*>(img.bits()), static_cast<unsigned long>(img.bytesPerLine())).clone();
}

void ImageProvider::updateImage(const QImage& image, int threshold)
{
    if(image.isNull())
        return;

    cv::Mat image_gray, image_canny;
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    QImage converted = image.convertToFormat(QImage::Format_RGB32);
    cv::Mat img = convertToMatCopy(converted, CV_8UC4);

    cv::cvtColor(img, image_gray, cv::COLOR_RGB2GRAY);
    cv::blur(image_gray, image_gray, cv::Size(3,3) );
    cv::Canny(image_gray, image_canny, threshold, threshold*2, 3 );

    cv::findContours(image_canny, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE, cv::Point(0, 0) );
    cv::Mat drawing = cv::Mat::zeros( image_canny.size(), CV_8UC4 );
    for(size_t i = 0; i < contours.size(); i++)
    {
        cv::Scalar color = cv::Scalar(m_rng.uniform(0, 255), m_rng.uniform(0,255), m_rng.uniform(0,255));
        drawContours(drawing, contours, static_cast<int>(i), color, 2, 4, hierarchy, 0, cv::Point());
    }

    QImage updated = convertToQImageCopy(drawing, QImage::Format_RGB32);

    this->thread()->msleep(50);
    emit imageReady(updated);
}
