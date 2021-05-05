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

#include <QImage>
#include <QPainter>
#include <QQuickPaintedItem>


class ImageItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ getImage WRITE setImage NOTIFY imageChanged)

public:
    ImageItem(QQuickItem *parent = nullptr);

public:
    QImage getImage() const;
    void setImage(const QImage &image);
    void paint(QPainter *painter);

signals:
    void imageChanged();

private:
    QImage m_image;
};
