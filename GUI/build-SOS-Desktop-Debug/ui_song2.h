/********************************************************************************
** Form generated from reading UI file 'song2.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONG2_H
#define UI_SONG2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Song2
{
public:
    QPushButton *pushButton;
    QLabel *countdownLabel;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Song2)
    {
        if (Song2->objectName().isEmpty())
            Song2->setObjectName(QString::fromUtf8("Song2"));
        Song2->resize(1123, 549);
        pushButton = new QPushButton(Song2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 30, 91, 41));
        countdownLabel = new QLabel(Song2);
        countdownLabel->setObjectName(QString::fromUtf8("countdownLabel"));
        countdownLabel->setGeometry(QRect(410, 180, 201, 51));
        countdownLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_2 = new QPushButton(Song2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(989, 461, 101, 51));

        retranslateUi(Song2);

        QMetaObject::connectSlotsByName(Song2);
    } // setupUi

    void retranslateUi(QDialog *Song2)
    {
        Song2->setWindowTitle(QCoreApplication::translate("Song2", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Song2", "Back", nullptr));
        countdownLabel->setText(QCoreApplication::translate("Song2", "TextLabel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Song2", "Continue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Song2: public Ui_Song2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONG2_H
