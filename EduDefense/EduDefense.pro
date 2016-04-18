HEADERS += \
    gameobject.h \
    enemy.h \
    moveable.h \
    tower.h \
    missle.h \
    activegameobject.h \
    exceptions.h \
    game.h \
    map.h \
    menu.h \
    chooselevel.h \
    statemanger.h \
    gameobjectcreator.h \
    kind_maps.h \
    gamemanager.h \
    player.h

SOURCES += \
    main.cpp \
    gameobject.cpp \
    enemy.cpp \
    moveable.cpp \
    tower.cpp \
    missle.cpp \
    activegameobject.cpp \
    exceptions.cpp \
    game.cpp \
    menu.cpp \
    statemanager.cpp \
    gameobjectcreator.cpp \
    gamemanager.cpp \
    player.cpp

LIBS += -LC:/SFML/lib

CONFIG(release, debug|release): LIBS += -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-graphics  -lsfml-audio -lsfml-window -lsfml-system

INCLUDEPATH += C:/SFML/include
DEPENDPATH += C:/SFML/include

QMAKE_CXXFLAGS += -std=c++11
