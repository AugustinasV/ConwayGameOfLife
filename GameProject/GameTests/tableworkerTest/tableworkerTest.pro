QT += testlib
QT += gui widgets

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

#TARGET = tst_tableworkertest

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

SOURCES += tst_tableworkertest.cpp \
    ../../GameApp/mainwindow.cpp \
    ../../GameApp/tablemodel.cpp \
    ../../GameApp/tableworker.cpp \

HEADERS += \
    ../../GameApp/mainwindow.h \
    ../../GameApp/tablemodel.h \
    ../../GameApp/tableworker.h \


INCLUDEPATH += ../../GameApp/


