#include "song2.h"
#include "ui_song2.h"
#include "results.h"
#include "song_list.h" 
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QLabel>  
#include <QVBoxLayout>
#include <unistd.h>
#include <string>
#include "./../../db_server/Client/Song.hpp"


Song2::Song2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Song2),
    count_down_V(3), 
    count_down_T(new QTimer(this)),
    lyricsTimer(new QTimer(this)),
    songlist(nullptr), 
    result(nullptr),
    formattedText(""),
    song(2),
    soundEffect(nullptr)
{
    ui->setupUi(this);
    this->showFullScreen();

    QFont font("Arial", 24, QFont::Bold); 
    ui->countdownLabel->setFont(font);
    ui->countdownLabel->setAlignment(Qt::AlignCenter); 
    std::string songString = song.getData(2);
    song.parseString(songString);
    std::string fp = "./../../shared_cache/"+ song.getLyricsFile();
    QString qstring_fp = QString::fromStdString(fp);
    loadLyricsFromFile(qstring_fp);

    ui->countdownLabel->setStyleSheet("QLabel { color: darkblue; background-color: lightblue; }");

    count_down_T->setInterval(1000); 
    connect(count_down_T, &QTimer::timeout, this, &Song2::updateCountdown);

    ui->pushButton_2->show();


 
    ui->countdownLabel->setText(QString::number(count_down_V));

    ui->countdownLabel->setMinimumSize(QSize(this->width(), this->height())); // This ensures the label will be as big as the window

    count_down_T->start(); 

    lyricsTimer = new QTimer(this);
    connect(lyricsTimer, &QTimer::timeout, this, &Song2::updateLyrics);
    lineCounter = 0;
     QVBoxLayout *mainLayout = new QVBoxLayout;  
     QHBoxLayout *bottomLayout = new QHBoxLayout;  

     mainLayout->addWidget(ui->countdownLabel);

     QPushButton *on_pushButton_clicked = new QPushButton("Back", this);
     bottomLayout->addWidget(on_pushButton_clicked);
     connect(on_pushButton_clicked, &QPushButton::clicked, this, &Song2::on_pushButton_clicked);

    
     bottomLayout->addStretch(1);

     ui->pushButton_2->setStyleSheet("QPushButton { font-size: 18pt; }");
     ui->pushButton_2->setText("Continue");
     bottomLayout->addWidget(ui->pushButton_2);
     connect(ui->pushButton_2, &QPushButton::clicked, this, &Song2::on_pushButton_2_clicked);

     mainLayout->addLayout(bottomLayout);

     setLayout(mainLayout);
}

Song2::~Song2()
{
    delete count_down_T; // Delete the timer
    delete ui;
    if (songlist) {
        delete songlist; // Delete songlist if it has been initialized
    }
}

void Song2::loadLyricsFromFile(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open the file for reading:" << filePath;
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        ghostLyrics.append(in.readLine());
    }
    file.close();


    if (!ghostLyrics.isEmpty()) {
        qDebug() << "Lyrics loaded successfully!";
        startLyricsDisplay();
    }
    else {
        qDebug() << "No lyrics loaded!";
    }
}

void Song2::updateCountdown()
{
    count_down_V--;
    if (count_down_V <= 0) {
        count_down_T->stop();
        ui->countdownLabel->setText("<span style='font-size: 30pt; color: darkblue;'>Ready!</span>");
        QTimer::singleShot(1000, this, &Song2::startLyricsDisplay);
    } else {
        ui->countdownLabel->setText(QString("<span style='color: darkblue;'>%1</span>").arg(count_down_V));
    }
}

// Funktion til at starte visning af teksten
void Song2::startLyricsDisplay()
{
    if (!lyricsTimer) {
            lyricsTimer = new QTimer(this);
            connect(lyricsTimer, &QTimer::timeout, this, &Song2::updateLyrics);
        }

        lineCounter = 0;
        int delayTime = 9000; // Initial delay time for the first line (7 seconds)
        lyricsTimer->start(delayTime);

        if (!soundEffect) {
            std::string fp = "./../../shared_cache/"+ song.getInstrumentalFile();
            QString qstring_fp = QString::fromStdString(fp);
            qDebug() << "lurt: "<<qstring_fp;
            soundEffect = new QSound(qstring_fp, this);
            soundEffect->play();
        }
}

// Funktion til at opdatere teksten
void Song2::updateLyrics()
{
    qDebug() << "Updating lyrics, lineCounter:" << lineCounter;

        // Check if there are lines to display
        if (lineCounter < ghostLyrics.size()) {
            QStringList stanza;
            // Display lines in groups of 4 (stanza)
            for (int i = 0; i < 2 && lineCounter < ghostLyrics.size(); ++i) {
                stanza << ghostLyrics.at(lineCounter);
                ++lineCounter;

            }

            // Join lines to form the stanza
            QString formattedText = stanza.join("<br/>");
            ui->countdownLabel->setText("<span style='color: darkblue;'>" + formattedText + "</span>");

            // Stop the existing timer
            if (lyricsTimer->isActive()) {
                lyricsTimer->stop();
            }

            // Adjust the delay time for each stanza
            int delayTime = 9000; // Adjust the delay time as needed
            if (lyricsTimer) {
                lyricsTimer->start(delayTime);
            }
        } else {
            qDebug() << "All lyrics displayed.";
            stopLyricsDisplay();
        }
}



void Song2::highlightCurrentLine(const QString &currentLine)
{
    qDebug() << "Highlighting line:" << currentLine;

        formattedText += "<span style='color: darkblue;'>" + currentLine + "</span><br/>";

        if (currentLine.endsWith("know") || currentLine.endsWith("life")) {
            // Display the stanza and reset the formatted text
            ui->countdownLabel->setText(formattedText);
            formattedText.clear();
            qDebug() << "Displayed stanza.";
        }
}

void Song2::stopLyricsDisplay()
{
    if (lyricsTimer) {
            lyricsTimer->stop();
        }

        if (soundEffect) {
            soundEffect->stop();
        }

        ui->countdownLabel->clear(); 
}

void Song2::on_pushButton_clicked() 
{
    if (!songlist) {
        songlist = new SongList(this);
    }
    songlist->show();
    hide();
    stopLyricsDisplay();  
}

void Song2::on_pushButton_2_clicked() {

    if (!result) {
        result = new Results(this);
    }
    result->show();
    hide();
    stopLyricsDisplay();  
    QSound::play("/dev/null");  
}