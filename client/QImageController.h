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
