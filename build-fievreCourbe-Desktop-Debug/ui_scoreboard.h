/********************************************************************************
** Form generated from reading UI file 'scoreboard.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREBOARD_H
#define UI_SCOREBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScoreBoard
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *ScoreBoard)
    {
        if (ScoreBoard->objectName().isEmpty())
            ScoreBoard->setObjectName(QString::fromUtf8("ScoreBoard"));
        ScoreBoard->resize(150, 300);
        verticalLayoutWidget = new QWidget(ScoreBoard);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 20, 151, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        retranslateUi(ScoreBoard);

        QMetaObject::connectSlotsByName(ScoreBoard);
    } // setupUi

    void retranslateUi(QWidget *ScoreBoard)
    {
        ScoreBoard->setWindowTitle(QApplication::translate("ScoreBoard", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ScoreBoard", "Score", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ScoreBoard: public Ui_ScoreBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREBOARD_H
