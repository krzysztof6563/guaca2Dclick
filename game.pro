#-------------------------------------------------
#
# Project created by QtCreator 2016-09-05T21:26:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game
TEMPLATE = app

win32:INCLUDEPATH = "C:\\SDL\\include"
win32:LIBS += -LC:\\SDL\\lib

LIBS +=  -lSDL2 -lSDL2_mixer

SOURCES += main.cpp\
        mainwindow.cpp \
    load.cpp \
    inventory.cpp \
    invform.cpp \
    sound.cpp \
    keypad.cpp \
    note.cpp \
    note_dialog.cpp \
    all_notes_dialog.cpp \
    mouse_qlabel.cpp \
    puzzleform.cpp \
    saving.cpp

HEADERS  += mainwindow.h \
    load.h \
    inventory.h \
    invform.h \
    sound.h \
    keypad.h \
    note.h \
    note_dialog.h \
    all_notes_dialog.h \
    mouse_qlabel.h \
    puzzleform.h \
    saving.h

FORMS    += mainwindow.ui \
    invform.ui \
    keypad.ui \
    note_dialog.ui \
    all_notes_dialog.ui \
    puzzleform.ui

CONFIG += c11

RESOURCES += \
    main.qrc
