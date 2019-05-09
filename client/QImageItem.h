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
