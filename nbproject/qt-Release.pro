# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/MinGW_QT-Windows
TARGET = neoxtrainer3
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
QT = core gui
SOURCES += main.cpp MainForm.cpp CharacterForm.cpp Character.cpp AboutForm.cpp Crypto.cpp DatabaseManager.cpp
HEADERS += AboutForm.h CharacterDelegate.h DatabaseManager.h CharacterForm.h Character.h MainForm.h Crypto.h
FORMS += CharacterForm.ui AboutForm.ui MainForm.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/MinGW_QT-Windows
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc.exe
QMAKE_CXX = g++.exe
DEFINES += 
INCLUDEPATH += 
LIBS += 
