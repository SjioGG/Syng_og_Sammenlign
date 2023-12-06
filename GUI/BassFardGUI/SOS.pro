QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    highscore.cpp \
    main.cpp \
    mainwindow.cpp \
    results.cpp \
    song1.cpp \
    song2.cpp \
    song_list.cpp

HEADERS += \
    highscore.h \
    mainwindow.h \
    results.h \
    song1.h \
    song2.h \
    song_list.h

FORMS += \
    highscore.ui \
    mainwindow.ui \
    results.ui \
    song1.ui \
    song2.ui \
    song_list.ui

OTHER_FILES += ghost-jb.txt JB-ghost.wav that-way.wav thatway.txt


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
