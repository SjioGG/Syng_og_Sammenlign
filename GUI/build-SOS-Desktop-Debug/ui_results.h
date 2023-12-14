/********************************************************************************
** Form generated from reading UI file 'results.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTS_H
#define UI_RESULTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Results
{
public:
    QPushButton *BackToMainMenu;
    QPushButton *BackToSongList;

    void setupUi(QDialog *Results)
    {
        if (Results->objectName().isEmpty())
            Results->setObjectName(QString::fromUtf8("Results"));
        Results->resize(1040, 582);
        BackToMainMenu = new QPushButton(Results);
        BackToMainMenu->setObjectName(QString::fromUtf8("BackToMainMenu"));
        BackToMainMenu->setGeometry(QRect(470, 470, 91, 41));
        BackToSongList = new QPushButton(Results);
        BackToSongList->setObjectName(QString::fromUtf8("BackToSongList"));
        BackToSongList->setGeometry(QRect(470, 530, 101, 41));

        retranslateUi(Results);

        QMetaObject::connectSlotsByName(Results);
    } // setupUi

    void retranslateUi(QDialog *Results)
    {
        Results->setWindowTitle(QCoreApplication::translate("Results", "Dialog", nullptr));
        BackToMainMenu->setText(QCoreApplication::translate("Results", "Menu", nullptr));
        BackToSongList->setText(QCoreApplication::translate("Results", "New Song", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Results: public Ui_Results {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTS_H
