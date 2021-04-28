#include "mainwindow.hpp"

#include <QApplication>
#include <QTranslator>
#include <QDebug>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  qDebug() << QLocale();

  QTranslator translator;
  if (translator.load(QLocale(), QLatin1String("QtInternationalization"), QLatin1String("_"))) {
    // Without this line, you see "Hello World!" instead
    a.installTranslator(&translator);
  } else {
    if (QLocale().language() != QLocale::English) {
      qDebug() << QString("Failed to load translator for ") + QLocale().name();
    } else {
      qDebug() << "No translation needed, this is already in English";
    }
  }

  MainWindow w;
  w.show();
  return a.exec();
}
