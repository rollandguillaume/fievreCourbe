/********************************************************************************
** Form generated from reading UI file 'configwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGWINDOW_H
#define UI_CONFIGWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigWindow
{
public:
    QLabel *label_n;
    QLineEdit *lineEdit_n2;
    QLabel *label_d;
    QLineEdit *lineEdit_n1;
    QLineEdit *lineEdit_g2;
    QPushButton *pushButton_start;
    QLineEdit *lineEdit_g1;
    QLabel *label_g;
    QCheckBox *checkBox_2;
    QLineEdit *lineEdit_d1;
    QLineEdit *lineEdit_d2;

    void setupUi(QWidget *ConfigWindow)
    {
        if (ConfigWindow->objectName().isEmpty())
            ConfigWindow->setObjectName(QString::fromUtf8("ConfigWindow"));
        ConfigWindow->resize(893, 436);
        label_n = new QLabel(ConfigWindow);
        label_n->setObjectName(QString::fromUtf8("label_n"));
        label_n->setGeometry(QRect(90, 120, 59, 14));
        lineEdit_n2 = new QLineEdit(ConfigWindow);
        lineEdit_n2->setObjectName(QString::fromUtf8("lineEdit_n2"));
        lineEdit_n2->setGeometry(QRect(90, 200, 113, 22));
        label_d = new QLabel(ConfigWindow);
        label_d->setObjectName(QString::fromUtf8("label_d"));
        label_d->setGeometry(QRect(460, 120, 59, 14));
        lineEdit_n1 = new QLineEdit(ConfigWindow);
        lineEdit_n1->setObjectName(QString::fromUtf8("lineEdit_n1"));
        lineEdit_n1->setGeometry(QRect(90, 160, 113, 22));
        lineEdit_g2 = new QLineEdit(ConfigWindow);
        lineEdit_g2->setObjectName(QString::fromUtf8("lineEdit_g2"));
        lineEdit_g2->setGeometry(QRect(320, 200, 113, 22));
        lineEdit_g2->setMaxLength(1);
        pushButton_start = new QPushButton(ConfigWindow);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(590, 160, 141, 22));
        lineEdit_g1 = new QLineEdit(ConfigWindow);
        lineEdit_g1->setObjectName(QString::fromUtf8("lineEdit_g1"));
        lineEdit_g1->setGeometry(QRect(320, 160, 113, 22));
        lineEdit_g1->setMaxLength(1);
        label_g = new QLabel(ConfigWindow);
        label_g->setObjectName(QString::fromUtf8("label_g"));
        label_g->setGeometry(QRect(320, 120, 59, 14));
        checkBox_2 = new QCheckBox(ConfigWindow);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(210, 200, 85, 20));
        checkBox_2->setChecked(true);
        lineEdit_d1 = new QLineEdit(ConfigWindow);
        lineEdit_d1->setObjectName(QString::fromUtf8("lineEdit_d1"));
        lineEdit_d1->setGeometry(QRect(460, 160, 113, 22));
        lineEdit_d1->setMaxLength(1);
        lineEdit_d2 = new QLineEdit(ConfigWindow);
        lineEdit_d2->setObjectName(QString::fromUtf8("lineEdit_d2"));
        lineEdit_d2->setGeometry(QRect(460, 200, 113, 22));
        lineEdit_d2->setMaxLength(1);

        retranslateUi(ConfigWindow);

        QMetaObject::connectSlotsByName(ConfigWindow);
    } // setupUi

    void retranslateUi(QWidget *ConfigWindow)
    {
        ConfigWindow->setWindowTitle(QApplication::translate("ConfigWindow", "Form", 0, QApplication::UnicodeUTF8));
        label_n->setText(QApplication::translate("ConfigWindow", "name", 0, QApplication::UnicodeUTF8));
        label_d->setText(QApplication::translate("ConfigWindow", "right", 0, QApplication::UnicodeUTF8));
        pushButton_start->setText(QApplication::translate("ConfigWindow", "start", 0, QApplication::UnicodeUTF8));
        label_g->setText(QApplication::translate("ConfigWindow", "left", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("ConfigWindow", "CheckBox", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConfigWindow: public Ui_ConfigWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGWINDOW_H
