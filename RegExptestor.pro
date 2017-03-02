#-------------------------------------------------
#
# Project created by QtCreator 2016-03-30T19:56:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = regexp_testor
TEMPLATE = app


SOURCES += source/main.cpp\
        source/customwindow.cpp \
    source/windowtitlebar.cpp \
    source/windowbutton.cpp \
    source/windowbuttonminimize.cpp \
    source/windowbuttonmaximize.cpp \
    source/windowbuttonclose.cpp \
    source/regexwindow.cpp

HEADERS  += header/customwindow.h \
    header/windowtitlebar.h \
    header/windowbutton.h \
    header/windowbuttonminimize.h \
    header/windowbuttonmaximize.h \
    header/windowbuttonclose.h \
    header/regexwindow.h

RESOURCES += \
    icon.qrc
