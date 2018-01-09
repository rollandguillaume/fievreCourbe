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
    bonus_reverse.cpp \
    bonus_ghost.cpp \
    dialog_name.cpp

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
    bonus_reverse.h \
    bonus_ghost.h \
    dialog_name.h

FORMS += \
    mainwindow.ui \
    dialog_help.ui \
    scoreboard.ui \
    startwindow.ui \
    dialog_key.ui \
    dialog_name.ui

RESOURCES += \
    resource.qrc
