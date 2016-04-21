HEADERS += \
    gameobject.h \
    enemy.h \
    moveable.h \
    tower.h \
    activegameobject.h \
    exceptions.h \
    game.h \
    map.h \
    menu.h \
    chooselevel.h \
    statemanger.h \
    gameobjectcreator.h \
    gamemanager.h \
    player.h \
    gamemenu.h \
    gameview.h \
    controller.h \
    path.h \
    defaultenemy.h \
    drawableobject.h \
    defaulttower.h \
    missile.h
    mapobject.h
SOURCES += \
    main.cpp \
    gameobject.cpp \
    enemy.cpp \
    moveable.cpp \
    tower.cpp \
    activegameobject.cpp \
    exceptions.cpp \
    game.cpp \
    menu.cpp \
    statemanager.cpp \
    gameobjectcreator.cpp \
    gamemanager.cpp \
    player.cpp \
    gameview.cpp \
    controller.cpp \
    path.cpp \
    defaultenemy.cpp \
    drawableobject.cpp \
    defaulttower.cpp \
    missile.cpp

LIBS += -LC:/SFML/lib

CONFIG(release, debug|release): LIBS += -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-graphics  -lsfml-audio -lsfml-window -lsfml-system

INCLUDEPATH += C:/SFML/include
DEPENDPATH += C:/SFML/include

QMAKE_CXXFLAGS += -std=c++11
