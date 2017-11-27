#ifndef DIALOG_KEY_H
#define DIALOG_KEY_H

#include <QDialog>
#include <QKeyEvent>

namespace Ui {
class Dialog_Key;
}

class Dialog_Key : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Key(QString label, QWidget *parent = 0);
    ~Dialog_Key();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

private:
    Ui::Dialog_Key *ui;
};

#endif // DIALOG_KEY_H
