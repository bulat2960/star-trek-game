QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game/gamecontroller.cpp \
    gamesettings.cpp \
    gui/mainwindow.cpp \
    gui/scene.cpp \
    gui/view.cpp \
    main.cpp \
    objects/blackhole.cpp \
    objects/galaxy.cpp \
    objects/object.cpp \
    objects/player.cpp \
    objects/quadrant.cpp \
    objects/star.cpp \
    objects/wormhole.cpp

HEADERS += \
    game/gamecontroller.h \
    gamesettings.h \
    gui/mainwindow.h \
    gui/scene.h \
    gui/view.h \
    objects/blackhole.h \
    objects/galaxy.h \
    objects/object.h \
    objects/player.h \
    objects/quadrant.h \
    objects/star.h \
    objects/wormhole.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
