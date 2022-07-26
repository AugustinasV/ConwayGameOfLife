#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QAbstractTableModel>
#include <QTimer>
//#include <QThread>
#include "tablemodel.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool running = false;
    int speed = 1000;

private:
    Ui::MainWindow *ui;
    TableModel *model;
    QTimer *timer;

public slots:
    void nextgeneration();      // do one generation                                (delete?)
    void startlaunch();         // start timer, set running to TRUE
    void stoplaunch();          // stop timer, set running to FALSE
    void sliderchanged(int);    // reset timer with new speed value
    void run();                 // for every timer timeout(): get next generation + update view
    bool timer_isruning();
};

#endif // MAINWINDOW_H
