#include "mainwindow.h"
//#include "tablemodel.h"
#include "ui_mainwindow.h"
//#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new TableModel;
    model->loadfromfile();
    ui->tableView->setModel(model);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(run()));

    ui->label_colcount->setText("collumns:"+QString::number(model->columnCount()));
    ui->label_rowcount->setText("rows:"+QString::number(model->rowCount()));

    ui->tableView->horizontalHeader()->hide();
    ui->tableView->verticalHeader()->hide();
    ui->tableView->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView->horizontalHeader()->setDefaultSectionSize(20);
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);

    ui->slider->setMaximum(2000);
    ui->slider->setMinimum(100);
    ui->slider->setValue(1000);

    connect(ui->nextgenbut,SIGNAL(released()), this, SLOT(nextgeneration()));
    connect(ui->launchbut,SIGNAL(released()), this, SLOT(startlaunch()));               // !!!
    connect(ui->stopbut,SIGNAL(released()), this, SLOT(stoplaunch()));
    connect(ui->slider,SIGNAL(valueChanged(int)),this,SLOT(sliderchanged(int)));

    connect(ui->tableView, SIGNAL(pressed(QModelIndex)),this->model, SLOT(cellclickupdate(QModelIndex)));
    connect(ui->addcolbut, SIGNAL(released()),this->model, SLOT(addcolbut_clicked()));
    connect(ui->addrowbut, SIGNAL(released()),this->model, SLOT(addrowbut_clicked()));
    connect(ui->removecolbut,SIGNAL(released()),this->model, SLOT(removecolbut_clicked()));
    connect(ui->removerowbut,SIGNAL(released()),this->model, SLOT(removerowbut_clicked()));
    connect(ui->output_current,SIGNAL(released()), this->model, SLOT(sendOutputRequestReceived()));

}

MainWindow::~MainWindow()
{
    delete model;
    delete ui;
}

void MainWindow::sliderchanged(int asd)
{
    timer->stop();
    speed = asd;
    timer->start(speed);
}

void MainWindow::nextgeneration()
{
    emit model->NextGenerationRequest();
    ui->tableView->viewport()->update();
}

void MainWindow::run()
{
    if (running == true)
    {
        emit model->NextGenerationRequest();
    }
    ui->tableView->viewport()->update();
    ui->label_time->setText("Time delay:"+ QString::number(speed)+"ms");
}

void MainWindow::startlaunch()
{
    running = true;
    QString s = QString::number(running);
    ui->label_running->setText("running:"+s);
    ui->label_colcount->setText("collumns:"+QString::number(model->columnCount()));
    ui->label_rowcount->setText("rows:"+QString::number(model->rowCount()));
    timer->start(speed);
}

void MainWindow::stoplaunch()
{
    running = false;
    QString s = QString::number(running);
    ui->label_running->setText("running:"+s);
    timer->stop();
}

bool MainWindow::timer_isruning()
{
    return timer->isActive();
}
