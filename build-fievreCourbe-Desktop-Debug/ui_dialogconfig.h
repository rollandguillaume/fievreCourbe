/********************************************************************************
** Form generated from reading UI file 'dialogconfig.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONFIG_H
#define UI_DIALOGCONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogConfig
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_right;
    QLineEdit *lineEdit_n_2;
    QLabel *label_name;
    QLineEdit *lineEdit_l_2;
    QLineEdit *lineEdit_r_1;
    QLineEdit *lineEdit_l_1;
    QLabel *label_left;
    QLineEdit *lineEdit_n_1;
    QLineEdit *lineEdit_r_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_valid;
    QPushButton *pushButton_annul;

    void setupUi(QDialog *DialogConfig)
    {
        if (DialogConfig->objectName().isEmpty())
            DialogConfig->setObjectName(QString::fromUtf8("DialogConfig"));
        DialogConfig->resize(396, 150);
        DialogConfig->setModal(true);
        gridLayoutWidget = new QWidget(DialogConfig);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 381, 87));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_right = new QLabel(gridLayoutWidget);
        label_right->setObjectName(QString::fromUtf8("label_right"));
        label_right->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_right, 0, 3, 1, 1);

        lineEdit_n_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_n_2->setObjectName(QString::fromUtf8("lineEdit_n_2"));

        gridLayout->addWidget(lineEdit_n_2, 2, 0, 1, 1);

        label_name = new QLabel(gridLayoutWidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_name, 0, 0, 1, 1);

        lineEdit_l_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_l_2->setObjectName(QString::fromUtf8("lineEdit_l_2"));
        lineEdit_l_2->setMaxLength(1);

        gridLayout->addWidget(lineEdit_l_2, 2, 2, 1, 1);

        lineEdit_r_1 = new QLineEdit(gridLayoutWidget);
        lineEdit_r_1->setObjectName(QString::fromUtf8("lineEdit_r_1"));
        lineEdit_r_1->setMaxLength(1);

        gridLayout->addWidget(lineEdit_r_1, 1, 3, 1, 1);

        lineEdit_l_1 = new QLineEdit(gridLayoutWidget);
        lineEdit_l_1->setObjectName(QString::fromUtf8("lineEdit_l_1"));
        lineEdit_l_1->setMaxLength(1);

        gridLayout->addWidget(lineEdit_l_1, 1, 2, 1, 1);

        label_left = new QLabel(gridLayoutWidget);
        label_left->setObjectName(QString::fromUtf8("label_left"));
        label_left->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_left, 0, 2, 1, 1);

        lineEdit_n_1 = new QLineEdit(gridLayoutWidget);
        lineEdit_n_1->setObjectName(QString::fromUtf8("lineEdit_n_1"));

        gridLayout->addWidget(lineEdit_n_1, 1, 0, 1, 1);

        lineEdit_r_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_r_2->setObjectName(QString::fromUtf8("lineEdit_r_2"));
        lineEdit_r_2->setMaxLength(1);

        gridLayout->addWidget(lineEdit_r_2, 2, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        pushButton_valid = new QPushButton(DialogConfig);
        pushButton_valid->setObjectName(QString::fromUtf8("pushButton_valid"));
        pushButton_valid->setGeometry(QRect(210, 120, 80, 22));
        pushButton_annul = new QPushButton(DialogConfig);
        pushButton_annul->setObjectName(QString::fromUtf8("pushButton_annul"));
        pushButton_annul->setGeometry(QRect(300, 120, 80, 22));

        retranslateUi(DialogConfig);
        QObject::connect(pushButton_valid, SIGNAL(clicked()), DialogConfig, SLOT(accept()));
        QObject::connect(pushButton_annul, SIGNAL(clicked()), DialogConfig, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogConfig);
    } // setupUi

    void retranslateUi(QDialog *DialogConfig)
    {
        DialogConfig->setWindowTitle(QApplication::translate("DialogConfig", "Configuration", 0, QApplication::UnicodeUTF8));
        label_right->setText(QApplication::translate("DialogConfig", "Droite", 0, QApplication::UnicodeUTF8));
        label_name->setText(QApplication::translate("DialogConfig", "Nom", 0, QApplication::UnicodeUTF8));
        label_left->setText(QApplication::translate("DialogConfig", "Gauche", 0, QApplication::UnicodeUTF8));
        pushButton_valid->setText(QApplication::translate("DialogConfig", "Valider", 0, QApplication::UnicodeUTF8));
        pushButton_annul->setText(QApplication::translate("DialogConfig", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogConfig: public Ui_DialogConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONFIG_H
