TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        celestialbody.cpp \
        main.cpp

CONFIG(debug, debug|release){
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window -lGL -lGLU

}

HEADERS += \
    celestialbody.h
