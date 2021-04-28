#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QTranslator>

class InternationalizationTest;

class MainWindow : public QMainWindow
{
  Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  protected:
    // this event is called, when a new translator is loaded or the system language is changed
    void changeEvent(QEvent*);

  //protected slots:
    // this slot is called by the language menu actions
    // void slotLanguageChanged(QAction* action);

  private:

    void updateText();

    // loads a language by the given language shortcur (e.g. de, en)
    void loadLanguage(const QString& rLanguage);
    bool switchTranslator(QTranslator& translator, const QString& filename);
    void createLanguageMenu(void);

    QTranslator m_translator; // contains the translations for this application
    // QTranslator m_translatorQt; // contains the translations for qt
    QString m_langPath; // Path of language files. This is always fixed to /languages
    QString m_currLang; // contains the currently loaded language

    QPushButton * m_button = nullptr;

    QMenu *m_langMenu;
    QAction *m_actionEN;
    QAction *m_actionFR;
    QAction *m_actionES;


    // For testing
    friend class ::InternationalizationTest;
};

#endif // MAINWINDOW_H
