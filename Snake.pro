#-------------------------------------------------
#
# Project created by QtCreator 2017-05-03T09:42:51
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snake
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    snakepart.cpp \
    movesnake.cpp \
    food.cpp \
    score.cpp \
    button.cpp \
    tableresults.cpp \
    userinfo.cpp

HEADERS  += \
    game.h \
    snakepart.h \
    movesnake.h \
    food.h \
    score.h \
    button.h \
    tableresults.h \
    userinfo.h

FORMS    += \
    tableresults.ui \
    userinfo.ui

RESOURCES += \
    resource.qrc
