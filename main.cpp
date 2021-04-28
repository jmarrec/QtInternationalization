#include "mainwindow.hpp"

#include <QApplication>
#include <QTranslator>
#include <QDebug>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QTranslator translator;
  if (translator.load("QtInternationalization_es_ES")) {
    // Without this line, you see "Hello World!" instead
    a.installTranslator(&translator);
  } else {
    qDebug() << "Failed to load translator 'QtInternationalization_es_ES'\n";
  }

  MainWindow w;
  w.show();
  return a.exec();
}
