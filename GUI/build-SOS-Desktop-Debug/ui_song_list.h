/********************************************************************************
** Form generated from reading UI file 'song_list.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONG_LIST_H
#define UI_SONG_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SongList
{
public:
    QPushButton *pushButton;
    QPushButton *Song_2;
    QPushButton *Song_1;
    QLabel *label;

    void setupUi(QDialog *SongList)
    {
        if (SongList->objectName().isEmpty())
            SongList->setObjectName(QString::fromUtf8("SongList"));
        SongList->resize(700, 500);
        SongList->setLayoutDirection(Qt::RightToLeft);
        SongList->setAutoFillBackground(false);
        pushButton = new QPushButton(SongList);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 121, 22));
        Song_2 = new QPushButton(SongList);
        Song_2->setObjectName(QString::fromUtf8("Song_2"));
        Song_2->setGeometry(QRect(380, 190, 261, 91));
        Song_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3399FF;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #66B2FF;\n"
"}\n"
"border-radius: 10px;"));
        Song_1 = new QPushButton(SongList);
        Song_1->setObjectName(QString::fromUtf8("Song_1"));
        Song_1->setGeometry(QRect(60, 190, 271, 91));
        Song_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3399FF;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #66B2FF;\n"
"}\n"
"border-radius: 10px;"));
        label = new QLabel(SongList);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 80, 521, 51));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);

        retranslateUi(SongList);

        QMetaObject::connectSlotsByName(SongList);
    } // setupUi

    void retranslateUi(QDialog *SongList)
    {
        SongList->setWindowTitle(QCoreApplication::translate("SongList", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("SongList", "Back", nullptr));
        Song_2->setText(QCoreApplication::translate("SongList", "BS boys - I want it that way", nullptr));
        Song_1->setText(QCoreApplication::translate("SongList", "Song 1: JB - Ghost", nullptr));
        label->setText(QCoreApplication::translate("SongList", "Choose between these two songs:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SongList: public Ui_SongList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONG_LIST_H
