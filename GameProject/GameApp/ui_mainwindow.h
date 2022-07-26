/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_running;
    QLabel *label_rowcount;
    QLabel *label_colcount;
    QSpacerItem *verticalSpacer_5;
    QPushButton *nextgenbut;
    QPushButton *launchbut;
    QPushButton *stopbut;
    QPushButton *output_current;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_time;
    QSlider *slider;
    QSpacerItem *verticalSpacer_3;
    QPushButton *addrowbut;
    QPushButton *addcolbut;
    QPushButton *removerowbut;
    QPushButton *removecolbut;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEnabled(true);

        gridLayout_2->addWidget(tableView, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        verticalSpacer = new QSpacerItem(78, 59, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_running = new QLabel(centralwidget);
        label_running->setObjectName(QString::fromUtf8("label_running"));

        verticalLayout->addWidget(label_running);

        label_rowcount = new QLabel(centralwidget);
        label_rowcount->setObjectName(QString::fromUtf8("label_rowcount"));

        verticalLayout->addWidget(label_rowcount);

        label_colcount = new QLabel(centralwidget);
        label_colcount->setObjectName(QString::fromUtf8("label_colcount"));

        verticalLayout->addWidget(label_colcount);

        verticalSpacer_5 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        nextgenbut = new QPushButton(centralwidget);
        nextgenbut->setObjectName(QString::fromUtf8("nextgenbut"));

        verticalLayout->addWidget(nextgenbut);

        launchbut = new QPushButton(centralwidget);
        launchbut->setObjectName(QString::fromUtf8("launchbut"));
        launchbut->setCheckable(false);
        launchbut->setChecked(false);

        verticalLayout->addWidget(launchbut);

        stopbut = new QPushButton(centralwidget);
        stopbut->setObjectName(QString::fromUtf8("stopbut"));

        verticalLayout->addWidget(stopbut);

        output_current = new QPushButton(centralwidget);
        output_current->setObjectName(QString::fromUtf8("output_current"));

        verticalLayout->addWidget(output_current);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        label_time = new QLabel(centralwidget);
        label_time->setObjectName(QString::fromUtf8("label_time"));

        verticalLayout->addWidget(label_time);

        slider = new QSlider(centralwidget);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider);

        verticalSpacer_3 = new QSpacerItem(78, 37, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        addrowbut = new QPushButton(centralwidget);
        addrowbut->setObjectName(QString::fromUtf8("addrowbut"));

        verticalLayout->addWidget(addrowbut);

        addcolbut = new QPushButton(centralwidget);
        addcolbut->setObjectName(QString::fromUtf8("addcolbut"));

        verticalLayout->addWidget(addcolbut);

        removerowbut = new QPushButton(centralwidget);
        removerowbut->setObjectName(QString::fromUtf8("removerowbut"));

        verticalLayout->addWidget(removerowbut);

        removecolbut = new QPushButton(centralwidget);
        removecolbut->setObjectName(QString::fromUtf8("removecolbut"));

        verticalLayout->addWidget(removecolbut);

        verticalSpacer_2 = new QSpacerItem(78, 56, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout_2->addLayout(verticalLayout, 0, 1, 1, 1);

        gridLayout_2->setColumnStretch(0, 10);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(nextgenbut, SIGNAL(pressed()), tableView, SLOT(reset()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_running->setText(QApplication::translate("MainWindow", "Running", nullptr));
        label_rowcount->setText(QApplication::translate("MainWindow", "Row count:", nullptr));
        label_colcount->setText(QApplication::translate("MainWindow", "Col count:", nullptr));
        nextgenbut->setText(QApplication::translate("MainWindow", "Next gen.", nullptr));
        launchbut->setText(QApplication::translate("MainWindow", "Start", nullptr));
        stopbut->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        output_current->setText(QApplication::translate("MainWindow", "File output", nullptr));
        label_time->setText(QApplication::translate("MainWindow", "Time delay:", nullptr));
        addrowbut->setText(QApplication::translate("MainWindow", "Add Row", nullptr));
        addcolbut->setText(QApplication::translate("MainWindow", "Add Col", nullptr));
        removerowbut->setText(QApplication::translate("MainWindow", "Remove Row", nullptr));
        removecolbut->setText(QApplication::translate("MainWindow", "Remove Col", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
