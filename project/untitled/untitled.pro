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
    event_listener.cpp \
    main_window.cpp

HEADERS  += \
    event_listener.h \
    game_start.h \
    main_window.h

FORMS    +=

CONFIG(release, debug|release): LIBS += -lsfml-graphics -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-graphics -lsfml-window -lsfml-system


