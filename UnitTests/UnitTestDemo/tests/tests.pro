#-------------------------------------------------
#
# Project created by QtCreator 2018-07-08T18:32:37
#
#-------------------------------------------------

QT       += core gui testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#QT       -= gui

TARGET = tst_teststest
CONFIG   += console
#CONFIG   -= app_bundle

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

top_srcdir=$$PWD

SOURCES += \
        tst_teststest.cpp \
        $$top_srcdir\../compare.cpp \
        $$top_srcdir\../testtextedit.cpp

HEADERS += $$top_srcdir\../compare.h \
           $$top_srcdir\../testtextedit.h



INCLUDEPATH ''= $$


DEFINES += SRCDIR=\\\"$$PWD/\\\"

