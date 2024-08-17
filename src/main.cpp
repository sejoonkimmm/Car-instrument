#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "CANBusReader.h"
#include "Speedometer.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    CANBusReader reader("can0");
    Speedometer speedometer;

    QObject::connect(&reader, &CANBusReader::newData, [=](int speed) {
        double circumference = 2 * M_PI * 3.35;
        double rps = static_cast<double>(speed) / 20;
        double speedCmPerSec = circumference * rps;
        qDebug() << speedCmPerSec << " cm/s";
    });
    QObject::connect(&reader, &CANBusReader::newData, &speedometer, &Speedometer::setSpeed);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    QQmlContext* rootContext = engine.rootContext();
    rootContext->setContextProperty("speedometer", &speedometer);

    return app.exec();
}
