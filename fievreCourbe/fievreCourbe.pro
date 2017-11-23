QT += widgets
QT += gui
QT += core
CONFIG += console


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    dialog_help.cpp \
    gamewindow.cpp \
    snake.cpp \
    scoreboard.cpp \
    wall.cpp \
    config.cpp \
    startwindow.cpp

HEADERS += \
    mainwindow.h \
    dialog_help.h \
    gamewindow.h \
    snake.h \
    scoreboard.h \
    wall.h \
    config.h \
    startwindow.h

FORMS += \
    mainwindow.ui \
    dialog_help.ui \
    scoreboard.ui \
    startwindow.ui
