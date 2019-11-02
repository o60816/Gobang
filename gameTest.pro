#-------------------------------------------------
#
# Project created by QtCreator 2014-07-31T19:55:35
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gameTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    chess.cpp \
    blackchess.cpp \
    whitechess.cpp \
    createchess.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    chess.h \
    blackchess.h \
    whitechess.h \
    createchess.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    photo.qrc
