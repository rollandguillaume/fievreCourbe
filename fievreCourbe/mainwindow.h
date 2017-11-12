#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialog_help.h>
#include <QStackedWidget>
#include <configwindow.h>
#include <gamewindow.h>
#include <QComboBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Dialog_help *dialog_help;

    QStackedWidget *stack;
    ConfigWindow *config_win;
    GameWindow *game_win;

public slots:
    void dialogHelp();
    void showConfig();
    void showGame();
};

#endif // MAINWINDOW_H
