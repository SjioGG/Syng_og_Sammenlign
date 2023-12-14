// song1.cpp
#include "song1.h"
#include "ui_song1.h"
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

// Initialiser statisk medlemsvariabel
QSound* Song1::soundEffect = nullptr;

Song1::Song1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Song1),
    count_down_V(10), // Start nedtællingen fra 10
    count_down_T(new QTimer(this)), // Initialiser timeren
    lyricsTimer(new QTimer(this)),
    songlist(nullptr), // Initialiser songlist som nullptr
    result(nullptr),
    formattedText(""),
    song(1)
{
    ui->setupUi(this);
    this->showFullScreen();

    // Opsæt skrifttype og størrelse for nedtællingslabelen
    QFont font("Arial", 24, QFont::Bold); // Justér størrelsen efter behov
    ui->countdownLabel->setFont(font);
    ui->countdownLabel->setAlignment(Qt::AlignCenter); // Centrer teksten vandret og lodret

    // Hent sangtekster fra fil ved start
    std::string songString = song.getData(1);
    song.parseString(songString);
    std::string fp = "./../../shared_cache/"+ song.getLyricsFile();
    QString qstring_fp = QString::fromStdString(fp);
    loadLyricsFromFile(qstring_fp);

    // Sæt farven på nedtællingsnummeret til mørkeblåt og baggrund til lyseblå
    ui->countdownLabel->setStyleSheet("QLabel { color: darkblue; background-color: lightblue; }");

    count_down_T->setInterval(1000); // Sæt timeren til at udløse hvert sekund
    connect(count_down_T, &QTimer::timeout, this, &Song1::updateCountdown);

    ui->pushButton_2->show();

    // Sæt det initielle nedtællingsnummer med den passende stil
    ui->countdownLabel->setText(QString::number(count_down_V));

    // Justér labelens størrelse til at passe til vinduet eller det centrale område
    ui->countdownLabel->setMinimumSize(QSize(this->width(), this->height()));

    count_down_T->start(); // Start nedtællingen øjeblikkeligt

    lyricsTimer = new QTimer(this);
    connect(lyricsTimer, &QTimer::timeout, this, &Song1::updateLyrics);
    lineCounter = 0;

    // Opret layout
    QVBoxLayout *mainLayout = new QVBoxLayout;  // Brug QVBoxLayout for at stakke widgets vertikalt
    QHBoxLayout *bottomLayout = new QHBoxLayout;  // Brug QHBoxLayout for knapperne i bunden

    // Tilføj nedtællingslabelen til mainLayout
    mainLayout->addWidget(ui->countdownLabel);

    // Opret "Back" knappen og tilføj den til bottomLayout
    QPushButton *on_pushButton_clicked = new QPushButton("Back", this);
    bottomLayout->addWidget(on_pushButton_clicked);
    connect(on_pushButton_clicked, &QPushButton::clicked, this, &Song1::on_pushButton_clicked);

    // Tilføj en strækfaktor mellem "Back" og "Continue" knapperne for at skubbe dem til hver sin side
    bottomLayout->addStretch(1);

    // Konfigurer "Continue" knappen og tilføj den til bottomLayout
    ui->pushButton_2->setStyleSheet("QPushButton { font-size: 18pt; }");
    ui->pushButton_2->setText("Continue");
    bottomLayout->addWidget(ui->pushButton_2);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Song1::on_pushButton_2_clicked);

    // Tilføj bottomLayout til bunden af mainLayout
    mainLayout->addLayout(bottomLayout);

    // Sæt mainLayout som layout for denne dialog
    setLayout(mainLayout);
}

// Destruktør
Song1::~Song1()
{
    delete count_down_T; // Slet timeren
    delete ui;
    if (songlist) {
        delete songlist; // Slet songlist, hvis den er initialiseret
    }
}

// Indlæs sangtekster fra fil
void Song1::loadLyricsFromFile(const QString &filePath) {
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

// Opdater nedtællingen
void Song1::updateCountdown()
{
    count_down_V--;
    if (count_down_V <= 0) {
        count_down_T->stop();
        ui->countdownLabel->setText("<span style='font-size: 30pt; color: darkblue;'>Ready!</span>");
        QTimer::singleShot(1000, this, &Song1::startLyricsDisplay);
    } else {
        ui->countdownLabel->setText(QString("<span style='color: darkblue;'>%1</span>").arg(count_down_V));
    }
}

// Start visning af sangtekster
void Song1::startLyricsDisplay() {
    connect(lyricsTimer, &QTimer::timeout, this, &Song1::updateLyrics);
    lineCounter = 0;
    int delayTime = 14000; // Initial forsinkelse for første linje (14 sekunder)
    lyricsTimer->QTimer::start(delayTime);

    if (!soundEffect) {
        std::string fp = "./../../shared_cache/"+ song.getInstrumentalFile();
        QString qstring_fp = QString::fromStdString(fp);
        qDebug() << "lurt: "<<qstring_fp;
        // Load the lyrics from the file at the start
        soundEffect = new QSound(qstring_fp, this);
        soundEffect->play();
    }
}

// Opdater visningen af sangtekster
void Song1::updateLyrics() {
    qDebug() << "Updating lyrics, lineCounter:" << lineCounter;

    // Tjek, om der er linjer at vise
    if (lineCounter < ghostLyrics.size()) {
        QStringList stanza;
        // Vis linjer i grupper af 4 (stanza)
        for (int i = 0; i < 4 && lineCounter < ghostLyrics.size(); ++i) {
            stanza << ghostLyrics.at(lineCounter);
            ++lineCounter;
        }

        // Saml linjer for at danne stanzan
        QString formattedText = stanza.join("<br/>");
        ui->countdownLabel->setText("<span style='color: darkblue;'>" + formattedText + "</span>");

        // Stop den eksisterende timer
        if (lyricsTimer->isActive()) {
            lyricsTimer->stop();
        }

        // Justér forsinkelsestiden for hver stanza
        int delayTime = 1000000; // Justér forsinkelsestiden efter behov
        if (lyricsTimer) {
            lyricsTimer->start(delayTime);
        }
    } else {
        qDebug() << "All lyrics displayed.";
        stopLyricsDisplay();
    }
}

// Fremhæv den aktuelle linje
void Song1::highlightCurrentLine(const QString &currentLine) {
    qDebug() << "Highlighting line:" << currentLine;

    // Tilføj den aktuelle linje til den formaterede tekst
    formattedText += "<span style='color: darkblue;'>" + currentLine + "</span><br/>";

    // Tjek, om den aktuelle linje er slutningen på en stanza
    if (currentLine.endsWith("know") || currentLine.endsWith("life")) {
        // Vis stanza og nulstil formateret tekst
        ui->countdownLabel->setText(formattedText);
        formattedText.clear();
        qDebug() << "Displayed stanza.";
    }
}

// Stop visning af sangtekster
void Song1::stopLyricsDisplay() {
    if (lyricsTimer) {
        lyricsTimer->stop();
    }

    // Stop lyden ved hjælp af QSound
    if (soundEffect) {
        soundEffect->stop();
    }

    ui->countdownLabel->clear(); // Ryd tekstområdet, når visningen stopper
}

// Logik ved klik på den første knap
void Song1::on_pushButton_clicked() {
    if (!songlist) {
        songlist = new SongList(this);
    }
    songlist->show();
    hide();
    stopLyricsDisplay();  // Stop lyden, når den første knap klikkes
}

// Logik ved klik på den anden knap
void Song1::on_pushButton_2_clicked() {
    if (!result) {
        result = new Results(this);
    }
    result->show();
    hide();

    stopLyricsDisplay();  // Stop lyden, når den anden knap klikkes
    QSound::play("/dev/null");  // Afspil en tom lyd for effektivt at stoppe eventuel pågående lyd
}
