# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist
TARGET = neoxtrainer
VERSION = 3.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
QT = core gui sql
SOURCES += main.cpp MainForm.cpp CharacterForm.cpp Character.cpp AboutForm.cpp Crypto.cpp MapleStory.cpp DatabaseManager.cpp CharacterDelegate.cpp
HEADERS += AboutForm.h MapleStory.h CharacterDelegate.h DatabaseManager.h CharacterForm.h Character.h MainForm.h Crypto.h
FORMS += CharacterForm.ui AboutForm.ui MainForm.ui
RESOURCES += neoxtrainer.qrc
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/MinGW_QT-Windows
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc.exe
QMAKE_CXX = g++.exe
DEFINES += 
INCLUDEPATH += 
LIBS += 
