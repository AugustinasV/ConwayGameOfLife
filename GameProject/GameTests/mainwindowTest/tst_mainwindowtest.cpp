#include <QtTest>

#include "mainwindow.h"

class mainwindowTest : public QObject
{
    Q_OBJECT

public:
    mainwindowTest();

private slots:
    void test_sliderchanged();
    void test_startlaunch();

private:
    MainWindow *window;
};

mainwindowTest::mainwindowTest()
{
    window = new MainWindow;
}

void mainwindowTest::test_sliderchanged()
{
    emit window->sliderchanged(2000);
    QVERIFY(window->speed == 2000);
}

void mainwindowTest::test_startlaunch()
{
    emit window->startlaunch();
    QVERIFY(window->running == true);
    QVERIFY(window->timer_isruning());
}

QTEST_MAIN(mainwindowTest)

#include "tst_mainwindowtest.moc"
