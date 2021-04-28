#include "mainwindow.hpp"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent),
    m_langPath(QApplication::applicationDirPath())
{


  m_button = new QPushButton(this);
  m_button->setMinimumSize(400, 205);
  setCentralWidget(m_button);
  createLanguageMenu();
  updateText();
}

MainWindow::~MainWindow()
{
}

void MainWindow::updateText() {

  if (m_actionES == nullptr) {
    // Create here?
  }

  QString name(". <FIXED VAL>. ");
  m_button->setText(tr("Hello World!") + name + tr("Another translatable phrase"));

  m_langMenu->setTitle(tr("&Language"));
  m_actionEN->setText(tr("English"));
  m_actionFR->setText(tr("French"));
  m_actionES->setText(tr("Spanish"));
}

void MainWindow::createLanguageMenu() {

  m_langMenu = menuBar()->addMenu("&Language");

  m_actionEN = new QAction(tr("English"), this);
  m_actionEN->setStatusTip("Change language to English");
  connect(m_actionEN, &QAction::triggered, this, [this]() { MainWindow::loadLanguage("en"); });
  m_langMenu->addAction(m_actionEN);

  m_actionFR = new QAction("French", this);
  m_actionFR->setStatusTip("Changer la langue vers le Français");
  connect(m_actionFR, &QAction::triggered, this, [this]() { MainWindow::loadLanguage("fr"); });
  m_langMenu->addAction(m_actionFR);

  m_actionES = new QAction(tr("Spanish"), this);
  m_actionES->setStatusTip("Cambiar idioma a español");
  connect(m_actionES, &QAction::triggered, this, [this]() { MainWindow::loadLanguage("es"); });
  m_langMenu->addAction(m_actionES);
}

bool MainWindow::switchTranslator(QTranslator& translator, const QString& filename) {
  // remove the old translator
  qApp->removeTranslator(&translator);

  // load the new translator
  auto fPath = QDir(m_langPath).filePath(filename);

  if(translator.load( fPath )) { //Here Path and Filename has to be entered because the system didn't find the QM Files else
    qApp->installTranslator(&translator);
    return true;
  } else {
    qDebug() << "Failed to load " << fPath;
  }

  return false;
}


void MainWindow::loadLanguage(const QString& rLanguage) {
  qDebug() << "Trying to change language from '" << m_currLang << "' to '" << rLanguage << "'.";
  if(m_currLang != rLanguage) {
    m_currLang = rLanguage;
    QLocale locale = QLocale(m_currLang);
    QLocale::setDefault(locale);
    QString languageName = QLocale::languageToString(locale.language());
    switchTranslator(m_translator, QString("QtInternationalization_%1.qm").arg(rLanguage));
    //switchTranslator(m_translatorQt, QString("qt_%1.qm").arg(rLanguage));
  }
}

void MainWindow::changeEvent(QEvent* event) {
 if(0 != event) {
  switch(event->type()) {
   // this event is send if a translator is loaded
   case QEvent::LanguageChange:
   {
    qDebug() << "Caught a QEvent::LanguageChange";
    // I am NOT using UI (Qt Designer), so that's problematic...
    // ui.retranslateUi(this);
    // Instead I set the tr text for the button inside a slot... call it in the Ctor, and call it again for each language change
    updateText();
    break;
   }
   // this event is send, if the system, language changes
   case QEvent::LocaleChange:
   {
    QString locale = QLocale::system().name();
    locale.truncate(locale.lastIndexOf('_'));
    loadLanguage(locale);
   }
   break;
  }
 }
 QMainWindow::changeEvent(event);
}
