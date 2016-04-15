CONFIG(release, debug|release): LIBS += -lsfml-graphics -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-graphics -lsfml-window -lsfml-system

SOURCES += \
    Menu.cpp \
    main.cpp

HEADERS += \
    Menu.h
