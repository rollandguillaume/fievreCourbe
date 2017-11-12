#ifndef FENETRE_H
#define FENETRE_H

#include <QWidget>
#include <QSlider>
#include <QProgressBar>
#include <QPushButton>
#include <QMainWindow>
#include "dialoghowtoplay.h"

class Fenetre : public QWidget
{
    Q_OBJECT
public:
    Fenetre();

private:

    QPushButton *btn;
    DialogHowToPlay *dhtp;


signals:

public slots:
    void openBox();
};

#endif // FENETRE_H
