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


    m.m_actionFR->trigger();
    QApplication::processEvents();
    QCOMPARE(m.m_button->text(), QString("Bonjour le Monde !. <FIXED VAL>. Une autre phrase traduisible"));

    m.m_actionEN->trigger();
    QApplication::processEvents();
    QCOMPARE(m.m_button->text(), QString("Hello World!. <FIXED VAL>. Another translatable phrase"));

}

QTEST_MAIN(InternationalizationTest)
#include <Internationalization_Test.moc>
