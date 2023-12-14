/********************************************************************************
** Form generated from reading UI file 'song1.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONG1_H
#define UI_SONG1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Song1
{
public:
    QPushButton *pushButton;
    QLabel *countdownLabel;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Song1)
    {
        if (Song1->objectName().isEmpty())
            Song1->setObjectName(QString::fromUtf8("Song1"));
        Song1->resize(1397, 737);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Song1->sizePolicy().hasHeightForWidth());
        Song1->setSizePolicy(sizePolicy);
        pushButton = new QPushButton(Song1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 480, 201, 81));
        countdownLabel = new QLabel(Song1);
        countdownLabel->setObjectName(QString::fromUtf8("countdownLabel"));
        countdownLabel->setGeometry(QRect(410, 190, 391, 201));
        countdownLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_2 = new QPushButton(Song1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(890, 480, 111, 51));

        retranslateUi(Song1);

        QMetaObject::connectSlotsByName(Song1);
    } // setupUi

    void retranslateUi(QDialog *Song1)
    {
        Song1->setWindowTitle(QCoreApplication::translate("Song1", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Song1", "Back", nullptr));
        countdownLabel->setText(QCoreApplication::translate("Song1", "TextLabel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Song1", "Continue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Song1: public Ui_Song1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONG1_H
