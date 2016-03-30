#-------------------------------------------------
#
# Project created by QtCreator 2014-12-17T21:14:42
#
#-------------------------------------------------

QT       += core gui
QT += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LinQedIn
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    profilo.cpp \
    username.cpp \
    utente.cpp \
    utentebasic.cpp \
    utentebusiness.cpp \
    utenteexecutive.cpp \
    rete.cpp \
    db.cpp \
    linqedadmin.cpp \
    linqedinclient.cpp \
    adminwindow.cpp \
    admininsertwindow.cpp \
    windowclient.cpp \
    windowclientprofilo.cpp \
    windowclientaggiorna.cpp \
    windowclientcerca.cpp \
    cambiatipologiautentewindow.cpp

HEADERS  += mainwindow.h \
    profilo.h \
    username.h \
    utentebasic.h \
    utentebusiness.h \
    utenteexecutive.h \
    rete.h \
    db.h \
    linqedadmin.h \
    linqedinclient.h \
    utente.h \
    adminwindow.h \
    admininsertwindow.h \
    windowclient.h \
    windowclientprofilo.h \
    windowclientaggiorna.h \
    windowclientcerca.h \
    cambiatipologiautentewindow.h

FORMS    += mainwindow.ui \
    adminwindow.ui \
    admininsertwindow.ui \
    windowclient.ui \
    windowclientprofilo.ui \
    windowclientaggiorna.ui \
    windowclientcerca.ui \
    cambiatipologiautentewindow.ui
