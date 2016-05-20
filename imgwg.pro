#-------------------------------------------------
#
# Project created by QtCreator 2016-04-07T19:01:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = imgwg
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

static { # everything below takes effect with CONFIG ''= static
 CONFIG+= static
 CONFIG += staticlib # this is needed if you create a static library, not a static executable
 DEFINES+= STATIC
 message("~~~ static build ~~~") # this is for information, that the static build is done
 win32: TARGET = $$join(TARGET,,,s) #this adds an s in the end, so you can seperate static build from
}

RC_FILE=images/logo.rc

DISTFILES += \
    images/androidproj.ico \
    images/studio.ico \
    images/logo.rc
