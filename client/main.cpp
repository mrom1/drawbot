#include "QImageController.h"
#include "QImageItem.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QImageController ImageController;

    qmlRegisterType<ImageItem>("com.drawbot.org", 1, 0, "ImageItem");

    engine.rootContext()->setContextProperty("ImageController", &ImageController);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

