/********************************************************************************
** Form generated from reading UI file 'highscore.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIGHSCORE_H
#define UI_HIGHSCORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_HighScore
{
public:
    QLabel *highscoreLabell;

    void setupUi(QDialog *HighScore)
    {
        if (HighScore->objectName().isEmpty())
            HighScore->setObjectName(QString::fromUtf8("HighScore"));
        HighScore->resize(1025, 563);
        highscoreLabell = new QLabel(HighScore);
        highscoreLabell->setObjectName(QString::fromUtf8("highscoreLabell"));
        highscoreLabell->setGeometry(QRect(80, 80, 851, 411));
        highscoreLabell->setAlignment(Qt::AlignCenter);

        retranslateUi(HighScore);

        QMetaObject::connectSlotsByName(HighScore);
    } // setupUi

    void retranslateUi(QDialog *HighScore)
    {
        HighScore->setWindowTitle(QCoreApplication::translate("HighScore", "Dialog", nullptr));
        highscoreLabell->setText(QCoreApplication::translate("HighScore", "highscoreLabel ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HighScore: public Ui_HighScore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIGHSCORE_H
