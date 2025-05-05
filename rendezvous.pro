<<<<<<< HEAD:Employe.pro
QT       += core gui charts sql printsupport widgets network
=======
QT       += core gui sql
QT += printsupport
QT += charts

QT += gui
QT += core gui widgets
>>>>>>> 0dd8fa2a00ddd5961ba08542899ebd609dcc60c1:rendezvous.pro


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT+= serialport
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Arduino_RDV.cpp \
    connection.cpp \
<<<<<<< HEAD:Employe.pro
    editemployeedialog.cpp \
    em.cpp \
    loginwindow.cpp \
=======
>>>>>>> 0dd8fa2a00ddd5961ba08542899ebd609dcc60c1:rendezvous.pro
    main.cpp \
    mainwindow.cpp \
    rendezvous.cpp

HEADERS += \
    Arduino_RDV.h \
    connection.h \
<<<<<<< HEAD:Employe.pro
    editemployeedialog.h \
    em.h \
    employe.h \
    loginwindow.h

FORMS += \
    editemployeedialog.ui \
    employe.ui \
    loginwindow.ui
=======
    mainwindow.h \
    rendez-vous.h \
    rendezvous.h

FORMS += \
    mainwindow.ui
>>>>>>> 0dd8fa2a00ddd5961ba08542899ebd609dcc60c1:rendezvous.pro

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc \
<<<<<<< HEAD:Employe.pro
    resource.qrc \
    resource.qrc \
    resource.qrc \
    rsc.qrc

DISTFILES += \
    sendmail.py
=======
    ressources.qrc


DISTFILES += \
    ../../Downloads/bell.svg
>>>>>>> 0dd8fa2a00ddd5961ba08542899ebd609dcc60c1:rendezvous.pro
