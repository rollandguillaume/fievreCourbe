/********************************************************************************
** Form generated from reading UI file 'dialoghowtoplay.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGHOWTOPLAY_H
#define UI_DIALOGHOWTOPLAY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogHowToPlay
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_play;
    QSlider *horizontalSlider_play;
    QProgressBar *progressBar_play;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *DialogHowToPlay)
    {
        if (DialogHowToPlay->objectName().isEmpty())
            DialogHowToPlay->setObjectName(QString::fromUtf8("DialogHowToPlay"));
        DialogHowToPlay->resize(274, 214);
        DialogHowToPlay->setModal(true);
        verticalLayout = new QVBoxLayout(DialogHowToPlay);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_play = new QLabel(DialogHowToPlay);
        label_play->setObjectName(QString::fromUtf8("label_play"));

        verticalLayout->addWidget(label_play);

        horizontalSlider_play = new QSlider(DialogHowToPlay);
        horizontalSlider_play->setObjectName(QString::fromUtf8("horizontalSlider_play"));
        horizontalSlider_play->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_play);

        progressBar_play = new QProgressBar(DialogHowToPlay);
        progressBar_play->setObjectName(QString::fromUtf8("progressBar_play"));
        progressBar_play->setValue(24);

        verticalLayout->addWidget(progressBar_play);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(DialogHowToPlay);
        QObject::connect(horizontalSlider_play, SIGNAL(valueChanged(int)), progressBar_play, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_play, SIGNAL(sliderMoved(int)), label_play, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(DialogHowToPlay);
    } // setupUi

    void retranslateUi(QDialog *DialogHowToPlay)
    {
        DialogHowToPlay->setWindowTitle(QApplication::translate("DialogHowToPlay", "Dialog", 0, QApplication::UnicodeUTF8));
        label_play->setText(QApplication::translate("DialogHowToPlay", "cr\303\251\303\251e avec qt designer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogHowToPlay: public Ui_DialogHowToPlay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGHOWTOPLAY_H
