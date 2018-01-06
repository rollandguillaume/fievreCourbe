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
#include "dialog_name.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget * parent = 0);
    ~MainWindow();
    void endGame(QString * winner);

private:
    Ui::MainWindow * ui;
    Dialog_help * dialog_help;
    Dialog_Name * dialog_name;
    GameWindow * game_win;
    StartWindow * start_win;
    ScoreBoard * sb;
    QLayout * layout;

public slots:
    void start();
    void newGame();
    void dialogHelp();

};

#endif // MAINWINDOW_H
