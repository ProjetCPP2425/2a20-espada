
QT += core gui sql

# Explicit Charts configuration
CONFIG += qt
QT += charts

# For MinGW specifically
win32-g++ {
    LIBS += -lQt$${QT_MAJOR_VERSION}Charts
    LIBS += -L$$[QT_INSTALL_LIBS]
}

# For MSVC
win32-msvc {
    LIBS += Qt$${QT_MAJOR_VERSION}Charts.lib
}
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buttondelegate.cpp \
    connection.cpp \
    editformationdialog.cpp \
    formation.cpp \
    main.cpp \
    formationmainwindow.cpp

HEADERS += \
    buttondelegate.h \
    connection.h \
    editformationdialog.h \
    formation.h \
    formationmainwindow.h

FORMS += \
    editformationdialog.ui \
    formationmainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
