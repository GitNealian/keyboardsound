QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    config.cpp \
    keydetectthread.cpp \
    main.cpp \
    matcher.cpp \
    sound.cpp

HEADERS += \
    config.h \
    desc.h \
    keydetectthread.h \
    matcher.h \
    sound.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
     msounds/alt.flac \
     msounds/backspace.flac \
     msounds/big_bracket.flac \
     msounds/blank.flac \
     msounds/capslock_off.flac \
     msounds/capslock_on.flac \
     msounds/comma.flac \
     msounds/continue.flac \
     msounds/continue.wav \
     msounds/ctrl.flac \
     msounds/ctrl_c.flac \
     msounds/ctrl_v.flac \
     msounds/delete.flac \
     msounds/down.flac \
     msounds/end.flac \
     msounds/enter.flac \
     msounds/exit.flac \
     msounds/home.flac \
     msounds/left.flac \
     msounds/normal_type.flac \
     msounds/normal_type.wav \
     msounds/period.flac \
     msounds/right.flac \
     msounds/semicolon.flac \
     msounds/shift.flac \
     msounds/shift_on.flac \
     msounds/splash.flac \
     msounds/tab.flac \
     msounds/up.flac \
     msounds/up.wav \
     msounds/windows.flac
