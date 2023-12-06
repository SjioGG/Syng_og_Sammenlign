#include "song_list.h"
#include "ui_song_list.h"
#include "song1.h"
#include <QGridLayout>
#include "song2.h"
#include "mainwindow.h"

SongList::SongList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SongList),
    mainmeny(nullptr),
    song1(nullptr),
    song2(nullptr)
{
    ui->setupUi(this);
    this->showFullScreen();

    // Konfigurerer overskriften
    ui->label->setText("Choose between these two songs:");
    QFont labelFont = ui->label->font();
    labelFont.setPointSize(16);
    labelFont.setBold(true);
    ui->label->setFont(labelFont);
    ui->label->setAlignment(Qt::AlignCenter);

    // Opretter gridlayout
    QGridLayout *gridLayout = new QGridLayout(this); // Husk at tilføje 'this' som parent til layoutet
    gridLayout->addWidget(ui->label, 0, 0, 1, 2, Qt::AlignCenter);
    gridLayout->addWidget(ui->Song_1, 1, 1);
    gridLayout->addWidget(ui->Song_2, 1, 0);
    gridLayout->addWidget(ui->pushButton, 2, 0, 1, 2, Qt::AlignCenter);

    ui->Song_1->setMinimumSize(QSize(200, 50));
    ui->Song_2->setMinimumSize(QSize(200, 50));
    ui->pushButton->setMinimumSize(QSize(200, 50));

    this->setLayout(gridLayout);

    connect(ui->Song_1, &QPushButton::clicked, this, &SongList::on_Song_1_clicked);
    connect(ui->Song_2, &QPushButton::clicked, this, &SongList::on_Song_2_clicked);
    connect(ui->pushButton, &QPushButton::clicked, this, &SongList::on_pushButton_clicked);
}

SongList::~SongList()
{
    delete ui;
    if (mainmeny) {
        delete mainmeny;
    }
}


void SongList::on_Song_1_clicked() {
    // Logik for når Song 1 vælges
    song1 = new Song1(this);
    song1->show();
    hide();
}

void SongList::on_Song_2_clicked() {
    // Logik for når Song 2 vælges
    song2 = new Song2(this);
    song2->show();
    hide();
}


void SongList::on_pushButton_clicked()
{
  if(!mainmeny){

      mainmeny = new MainWindow(this);
  }
  mainmeny->show();
  hide();
}

