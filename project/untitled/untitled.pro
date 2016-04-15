#-------------------------------------------------
#
# Project created by QtCreator 2016-04-03T19:03:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
    Game.cpp \
    EventListener.cpp \
    StateManager.cpp \
    Logfile.cpp

HEADERS  += \
    Game.h \
    EventListener.h \
    StateManager.h \
    Logfile.h

FORMS    +=

CONFIG(release, debug|release): LIBS += -lsfml-graphics -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-graphics -lsfml-window -lsfml-system


