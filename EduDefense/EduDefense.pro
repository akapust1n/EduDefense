CONFIG(release, debug|release): LIBS += -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-graphics  -lsfml-audio -lsfml-window -lsfml-system

HEADERS += \
    Menu.h \
    Game.h

SOURCES += \
    Menu.cpp \
    main.cpp \
    Game.cpp
