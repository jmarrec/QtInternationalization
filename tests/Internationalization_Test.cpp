#include "../mainwindow.hpp"

#include <QtTest/QtTest>
#include <QtWidgets>
#include <qnamespace.h>

class InternationalizationTest: public QObject
{
  Q_OBJECT

  private slots:
    void testGui();

  private:
    MainWindow m;

};

void InternationalizationTest::testGui()
{

    //QApplication::setActiveWindow(&m);

    m.m_actionES->trigger();
    QApplication::processEvents();
    QCOMPARE(m.m_button->text(), QString("\u00A1Hola mundo!. <FIXED VAL>. Otra frase traducible"));
    QCOMPARE(m.m_button->text(), QString("¡Hola mundo!. <FIXED VAL>. Otra frase traducible"));
    QCOMPARE(m.m_langMenu->title(), QString("&Idioma"));
    QCOMPARE(m.m_actionEN->text(), QString("Inglés"));
    QCOMPARE(m.m_actionFR->text(), QString("Frances"));
    QCOMPARE(m.m_actionES->text(), QString("Español"));

    m.m_actionFR->trigger();
    QApplication::processEvents();
    QCOMPARE(m.m_button->text(), QString("Bonjour le Monde !. <FIXED VAL>. Une autre phrase traduisible"));
    QCOMPARE(m.m_langMenu->title(), QString("&Langue"));
    QCOMPARE(m.m_actionEN->text(), QString("Anglais"));
    QCOMPARE(m.m_actionFR->text(), QString("Français"));
    QCOMPARE(m.m_actionES->text(), QString("Espagnol"));

    m.m_actionEN->trigger();
    QApplication::processEvents();
    QCOMPARE(m.m_button->text(), QString("Hello World!. <FIXED VAL>. Another translatable phrase"));
    QCOMPARE(m.m_langMenu->title(), QString("&Language"));
    QCOMPARE(m.m_actionEN->text(), QString("English"));
    QCOMPARE(m.m_actionFR->text(), QString("French"));
    QCOMPARE(m.m_actionES->text(), QString("Spanish"));
}

QTEST_MAIN(InternationalizationTest)
#include <Internationalization_Test.moc>
