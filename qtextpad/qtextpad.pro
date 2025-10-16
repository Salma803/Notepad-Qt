#-------------------------------------------------
#
# Project created by QtCreator 2013-03-04T20:40:46
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtextpad
TEMPLATE = app


SOURCES += main.cpp\
		mainwindow.cpp \
		numberedtextedit.cpp \
		replacedialog.cpp

HEADERS  += mainwindow.h \
    numberedtextedit.h \
    replacedialog.h

FORMS    += mainwindow.ui \
    replacedialog.ui

DISTFILES += \
    ../../../Downloads/qtextpad/qtextpad/build/Desktop_Qt_6_9_3_MinGW_64_bit-Debug/debug/README.md
