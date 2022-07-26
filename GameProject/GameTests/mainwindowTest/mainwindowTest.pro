QT += testlib
QT += gui widgets

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TARGET = tst_mainwindowtest

TEMPLATE = app

SOURCES +=  tst_mainwindowtest.cpp \
    ../../GameApp/mainwindow.cpp \
    ../../GameApp/tablemodel.cpp \
    ../../GameApp/tableworker.cpp \

HEADERS += \
    ../../GameApp/mainwindow.h \
    ../../GameApp/tablemodel.h \
    ../../GameApp/tableworker.h \

INCLUDEPATH += ../../GameApp/

