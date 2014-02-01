#-------------------------------------------------
#
# Project created by QtCreator 2014-01-31T23:32:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Grifball_Manager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    team.cpp \
    match.cpp

HEADERS  += mainwindow.h \
    player.h \
    team.h \
    match.h

FORMS    += mainwindow.ui
