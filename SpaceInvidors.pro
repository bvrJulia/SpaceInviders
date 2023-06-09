QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller.cpp \
    creature.cpp \
    gamedesighn.cpp \
    gameend.cpp \
    gamepause.cpp \
    gameplay.cpp \
    level.cpp \
    main.cpp \
    menu.cpp \
    monstr.cpp \
    player.cpp \
    shot.cpp

HEADERS += \
    controller.h \
    creature.h \
    gamedesighn.h \
    gameend.h \
    gamepause.h \
    gameplay.h \
    level.h \
    menu.h \
    monstr.h \
    player.h \
    shot.h

FORMS += \
    gamedesighn.ui \
    gameend.ui \
    gamepause.ui \
    gameplay.ui \
    menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resourse.qrc
