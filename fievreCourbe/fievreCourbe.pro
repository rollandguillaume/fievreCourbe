QT += widgets
QT += gui
QT += core

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    dialog_help.cpp \
    gamewindow.cpp \
    snake.cpp \
    scoreboard.cpp \
    wall.cpp \
    config.cpp \
    startwindow.cpp \
    dialog_key.cpp \
    corpssnake.cpp \
    bonus.cpp \
    bonus_closepath.cpp \
    bonus_reverse.cpp

HEADERS += \
    mainwindow.h \
    dialog_help.h \
    gamewindow.h \
    snake.h \
    scoreboard.h \
    wall.h \
    config.h \
    startwindow.h \
    dialog_key.h \
    corpssnake.h \
    bonus.h \
    bonus_closepath.h \
    bonus_reverse.h

FORMS += \
    mainwindow.ui \
    dialog_help.ui \
    scoreboard.ui \
    startwindow.ui \
    dialog_key.ui
