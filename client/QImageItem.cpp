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



#include "QImageItem.h"

ImageItem::ImageItem(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    QImage image = QImage(":/icons/newFile.png");
    setImage(image);
}

QImage ImageItem::getImage() const
{
    return m_image;
}

void ImageItem::setImage(const QImage &image)
{
    if(image != m_image) {
        m_image = image;
        emit imageChanged();
        update();
    }
}

void ImageItem::paint(QPainter *painter)
{
    if(m_image.isNull())
        return;

    QRectF bounding_rect = boundingRect();
    QImage scaled = m_image.scaledToHeight(bounding_rect.height());
    QPointF center = bounding_rect.center() - scaled.rect().center();

    if (center.x() < 0)
        center.setX(0);
    if (center.y() < 0)
        center.setY(0);
    painter->drawImage(center, scaled);
}
