#include "mainwindow.hpp"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  auto center = new QPushButton(tr("Hello World!"), this);
  center->setMinimumSize(400, 205);
  setCentralWidget(center);
}

MainWindow::~MainWindow()
{
}

