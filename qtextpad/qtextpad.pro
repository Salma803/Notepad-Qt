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
