#include "mainwindow.hpp"

#include <QApplication>
#include <QTranslator>
#include <QDebug>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  qDebug() << QLocale();

  MainWindow w;
  w.show();
  return a.exec();
}
