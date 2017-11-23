#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class StartWindow;
}

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

private:
    Ui::StartWindow *ui;
    void addJoueur();
    void deleteJoueur(int index);

private:
    std::vector<QString*> joueurs;
};

#endif // STARTWINDOW_H
