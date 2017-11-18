#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialog_help.h>
#include <QStackedWidget>
#include <dialogconfig.h>
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
    DialogConfig *dialogConfig;
    GameWindow *game_win;

public slots:
    void dialogHelp();
    void showConfig();
};

#endif // MAINWINDOW_H
