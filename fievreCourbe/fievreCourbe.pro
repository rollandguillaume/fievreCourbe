QT += widgets
QT += gui
QT += core
CONFIG += console

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    dialog_help.cpp \
    gamewindow.cpp \
    dialogconfig.cpp \
    snake.cpp \
    scoreboard.cpp \
    wall.cpp \
    config.cpp

HEADERS += \
    mainwindow.h \
    dialog_help.h \
    gamewindow.h \
    dialogconfig.h \
    snake.h \
    scoreboard.h \
    wall.h \
    config.h

FORMS += \
    mainwindow.ui \
    dialog_help.ui \
    dialogconfig.ui \
    scoreboard.ui
