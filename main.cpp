#include "mainwindow.hpp"

#include <QApplication>
#include <QTranslator>
#include <QDebug>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QTranslator translator;
  if (translator.load("QtInternalization_fr_FR")) {
    // Without this line, you see "Hello World!" instead
    a.installTranslator(&translator);
  } else {
    qDebug() << "Failed to load translator 'QtInternalization_fr_FR'\n";
  }

  MainWindow w;
  w.show();
  return a.exec();
}
