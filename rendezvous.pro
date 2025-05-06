QT       += core gui sql
QT += printsupport
QT += charts

QT += gui
QT += core gui widgets printsupport network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT+= serialport
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Arduino_RDV.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    rendezvous.cpp \
    loginwindow.cpp \
    arduino_employe.cpp

HEADERS += \
    Arduino_RDV.h \
    connection.h \
    mainwindow.h \
    rendez-vous.h \
    rendezvous.h  \
    loginwindow.h \
    arduino_employe.h

FORMS += \
    mainwindow.ui \
    loginwindow.ui \
    editemployeedialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc \
    ressources.qrc


DISTFILES += \
    ../../Downloads/bell.svg
