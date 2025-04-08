QT += core gui sql
QT += pdf
QT += charts
QT += core gui printsupport
QT += printsupport

RESOURCES += ressource.qrc
TARGET = ressource
TEMPLATE = app
CONFIG += c++17
QMAKE_CXXFLAGS += -Wno-redundant-decls

# === Fichiers sources ===
SOURCES += \
    main.cpp \
    ressource.cpp \
    connection.cpp \
    mainwindow.cpp

# === Fichiers headers ===
HEADERS += \
    connection.h \
    ressource.h \
    mainwindow.h

# === UI (Qt Designer) ===
FORMS += \
    mainwindow.ui

# === Fichier de ressources Qt ===

