#include "mainwindow.hpp"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{

  QString name(". <FIXED VAL>. ");
  auto center = new QPushButton(tr("Hello World!") + name + tr("Another translatable phrase"), this);
  center->setMinimumSize(400, 205);
  setCentralWidget(center);
}

MainWindow::~MainWindow()
{
}

