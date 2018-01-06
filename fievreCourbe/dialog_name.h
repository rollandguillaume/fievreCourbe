#ifndef DIALOG_NAME_H
#define DIALOG_NAME_H

#include <QDialog>

namespace Ui {
class Dialog_name;
}

class Dialog_name : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_name(QWidget *parent = 0);
    ~Dialog_name();

private:
    Ui::Dialog_name *ui;
};

#endif // DIALOG_NAME_H
