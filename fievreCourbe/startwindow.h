#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QLabel>

#include "snake.h"
#include "dialog_key.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();
    std::vector<QString> getJoueurs();

private:
    Ui::StartWindow *ui;
    void addJoueur();
    void deleteJoueur(int index);

private:
    std::vector<QString> joueurs;
    QString names[6] = {"Charlie", "Willem", "Buzz", "Jean", "Toto", "Pinkney"};
    QString colors[6] = {"red", "orange", "green", "blue", "grey", "pink"};
    Dialog_Key *dialog_key;

public slots:
    void addJoueurBtn();
};

#endif // STARTWINDOW_H
