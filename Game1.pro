TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

LIBS += -L"/SFML/lib"
LIBS += -lsfml-audio
LIBS += -lsfml-graphics
LIBS += -lsfml-network
LIBS += -lsfml-window
LIBS += -lsfml-system

INCLUDEPATH += "/SFML/include"
DEPENDPATH += "/SFML/include"

SOURCES += \
        main.cpp \
    player.cpp \
    platform.cpp \
    world.cpp \
    platfomtexture.cpp \
    coins.cpp \
    gameloop.cpp \
    button.cpp \
    messagebox.cpp \
    pause.cpp \
    endwindow.cpp \
    testme.cpp

DISTFILES += \
    Assets/characters.png \
    Maps/map1.m \
    Assets/Background/back.png \
    Assets/Background/middle.png \
    Maps/deco1.m \
    Maps/grassNrock.m \
    Assets/sheet.png \
    Assets/coins.png \
    Assets/ARCADECLASSIC.TTF

HEADERS += \
    player.h \
    platform.h \
    world.h \
    platfomtexture.h \
    coins.h \
    gameloop.h \
    button.h \
    messagebox.h \
    pause.h \
    endwindow.h \
    testme.h

