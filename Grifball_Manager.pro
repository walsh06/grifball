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
    match.cpp \
    ball.cpp \
    filehelper.cpp \
    matchscreen.cpp \
    tournament.cpp \
    tournamentscreen.cpp

HEADERS  += mainwindow.h \
    player.h \
    team.h \
    match.h \
    ball.h \
    filehelper.h \
    matchscreen.h \
    team.h \
    tournament.h \
    tournamentscreen.h

FORMS    += mainwindow.ui \
    matchscreen.ui \
    tournamentscreen.ui

QMAKE_CXXFLAGS += -std=c++11
