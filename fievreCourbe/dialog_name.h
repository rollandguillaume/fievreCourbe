#ifndef DIALOG_NAME_H
#define DIALOG_NAME_H

#include <QDialog>

namespace Ui {
class Dialog_Name;
}

class Dialog_Name : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Name(QString winner, QWidget *parent = 0);
    ~Dialog_Name();

private:
    Ui::Dialog_Name *ui;
};

#endif // DIALOG_NAME_H
