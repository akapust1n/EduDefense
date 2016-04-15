CONFIG(release, debug|release): LIBS += -lsfml-graphics -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-graphics -lsfml-window -lsfml-system

HEADERS += \
    Menu.h

SOURCES += \
    Menu.cpp \
    main.cpp
