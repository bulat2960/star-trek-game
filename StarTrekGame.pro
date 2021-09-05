QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    blackhole.cpp \
    galaxy.cpp \
    gamecontroller.cpp \
    gamesettings.cpp \
    guicontroller.cpp \
    main.cpp \
    mainwindow.cpp \
    object.cpp \
    player.cpp \
    quadrant.cpp \
    scene.cpp \
    star.cpp \
    view.cpp \
    wormhole.cpp

HEADERS += \
    blackhole.h \
    galaxy.h \
    gamecontroller.h \
    gamesettings.h \
    guicontroller.h \
    mainwindow.h \
    object.h \
    player.h \
    quadrant.h \
    scene.h \
    star.h \
    view.h \
    wormhole.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
