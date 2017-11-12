/********************************************************************************
** Form generated from reading UI file 'dialog_help.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_HELP_H
#define UI_DIALOG_HELP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Dialog_help
{
public:
    QLabel *label_contenuHelp;

    void setupUi(QDialog *Dialog_help)
    {
        if (Dialog_help->objectName().isEmpty())
            Dialog_help->setObjectName(QString::fromUtf8("Dialog_help"));
        Dialog_help->setWindowModality(Qt::NonModal);
        Dialog_help->resize(400, 300);
        Dialog_help->setModal(false);
        label_contenuHelp = new QLabel(Dialog_help);
        label_contenuHelp->setObjectName(QString::fromUtf8("label_contenuHelp"));
        label_contenuHelp->setGeometry(QRect(70, 70, 151, 131));

        retranslateUi(Dialog_help);

        QMetaObject::connectSlotsByName(Dialog_help);
    } // setupUi

    void retranslateUi(QDialog *Dialog_help)
    {
        Dialog_help->setWindowTitle(QApplication::translate("Dialog_help", "Dialog Help", 0, QApplication::UnicodeUTF8));
        label_contenuHelp->setText(QApplication::translate("Dialog_help", "contenu help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_help: public Ui_Dialog_help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_HELP_H
