#-------------------------------------------------
#
# Project created by QtCreator 2016-10-29T23:49:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = aaah
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Command.cpp \
    CommandWords.cpp \
    Room.cpp \
    Parser.cpp \
    item.cpp

HEADERS  += mainwindow.h \
    Command.h \
    CommandWords.h \
    Room.h \
    Parser.h \
    item.h

FORMS    += mainwindow.ui

DISTFILES += \
    ParkMap.png
