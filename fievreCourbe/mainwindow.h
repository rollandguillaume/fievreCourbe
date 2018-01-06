#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QStackedWidget>
#include <QComboBox>

#include <iostream>

#include "dialog_help.h"
#include "gamewindow.h"
#include "startwindow.h"
#include "scoreboard.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget * parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow * ui;
    Dialog_help * dialog_help;
    GameWindow * game_win;
    StartWindow * start_win;
    ScoreBoard * sb;
    QLayout * layout;

public slots:
    void start();
    void test();
    void dialogHelp();
};

#endif // MAINWINDOW_H
