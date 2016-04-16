HEADERS += \
    Menu.h \
    Game.h \
    Exceptions.h \
    gameobject.h \
    enemy.h \
    moveable.h \
    tower.h \
    Map.h \
    missle.h

SOURCES += \
    Menu.cpp \
    main.cpp \
    Game.cpp \
    Exceptions.cpp \
    gameobject.cpp \
    enemy.cpp \
    moveable.cpp \
    tower.cpp \
    missle.cpp

LIBS += -LC:/SFML/lib

CONFIG(release, debug|release): LIBS += -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-graphics  -lsfml-audio -lsfml-window -lsfml-system

INCLUDEPATH += C:/SFML/include
DEPENDPATH += C:/SFML/include

QMAKE_CXXFLAGS += -std=c++11
