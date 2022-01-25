# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = BibliographieGUI
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += BiblioJournalInterface.cpp BiblioOuvrageInterface.cpp BiblioSupprimeInterface.cpp BibliographieInterface.cpp main.cpp
HEADERS += BiblioJournalInterface.h BiblioOuvrageInterface.h BiblioSupprimeInterface.h BibliographieInterface.h
FORMS += BiblioJournalInterface.ui BiblioOuvrageInterface.ui BiblioSupprimeInterface.ui BibliographieInterface.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++-10
DEFINES += 
INCLUDEPATH += ../SourceTP4 
LIBS += ../SourceTP4/dist/Debug/GNU-Linux/libsourcetp4.a  
