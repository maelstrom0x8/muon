#include "muon.h"
#include "trackmodel.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QWindow>


int main(int argc, char *argv[]) {

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
  QCoreApplication::setApplicationVersion("1.0.0");
  QCoreApplication::setOrganizationDomain("org.xio.muon");
  QCoreApplication::setOrganizationName("xio");
  QCoreApplication::setApplicationName("muon");

  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;
  auto root = engine.rootContext();
  muon::TrackModel model;

  root->setContextProperty("__model", &model);
  

  const QUrl url(QStringLiteral("qrc:/Muon.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}