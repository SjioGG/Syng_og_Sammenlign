#include "song2.h"
#include "ui_song2.h"
#include "results.h"
#include "song_list.h" // Ensure this is correctly included
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QLabel>  // Include QLabel library
#include <QVBoxLayout>

QSound* Song2::soundEffect = nullptr;

Song2::Song2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Song2),
    count_down_V(3), // Start the countdown from 3
    count_down_T(new QTimer(this)), // Initialize the timer
    songlist(nullptr), // Initialize songlist as nullptr
    result(nullptr),
    formattedText("")
{
    ui->setupUi(this);
    this->showFullScreen();

    // Setup the font and size for the countdown label
    QFont font("Arial", 24, QFont::Bold); // Adjust the size as needed
    ui->countdownLabel->setFont(font);
    ui->countdownLabel->setAlignment(Qt::AlignCenter); // Center the text in the label horizontally and vertically

    // Load the lyrics from the file at the start
    loadLyricsFromFile("/home/stud/Documents/NyBASGUI/NyGUI/NYGUI/SOSr/SOS/thatway.txt");

    // Set the color of the countdown number to dark blue and background to light blue
    ui->countdownLabel->setStyleSheet("QLabel { color: darkblue; background-color: lightblue; }");

    count_down_T->setInterval(1000); // Set timer to trigger every second
    connect(count_down_T, &QTimer::timeout, this, &Song2::updateCountdown);

    ui->pushButton_2->show();


    // Set the initial countdown number with the appropriate style
    ui->countdownLabel->setText(QString::number(count_down_V));

    // Adjust the label size to fit the screen or central area
    ui->countdownLabel->setMinimumSize(QSize(this->width(), this->height())); // This ensures the label will be as big as the window

    count_down_T->start(); // Start the countdown immediately

    lyricsTimer = new QTimer(this);
    connect(lyricsTimer, &QTimer::timeout, this, &Song2::updateLyrics);
    lineCounter = 0;
    // Opret layout
     QVBoxLayout *mainLayout = new QVBoxLayout;  // Brug QVBoxLayout for at stacke widgets vertikalt
     QHBoxLayout *bottomLayout = new QHBoxLayout;  // Brug QHBoxLayout for knapperne i bunden

     // Tilføj din countdownLabel til mainLayout
     mainLayout->addWidget(ui->countdownLabel);

     // Opret "Back" knappen og tilføj den tsil bottomLayout
     QPushButton *on_pushButton_clicked = new QPushButton("Back", this);
     bottomLayout->addWidget(on_pushButton_clicked);
     connect(on_pushButton_clicked, &QPushButton::clicked, this, &Song2::on_pushButton_clicked);

     // Tilføj en strækfaktor mellem "Back" og "Continue" knapperne for at skubbe dem til hver sin side
     // Tilføj en strækfaktor mellem "Back" og "Continue" knapperne for at skubbe dem til hver sin side
     bottomLayout->addStretch(1);

     // Konfigurer "Continue" knappen og tilføj den til bottomLayout
     ui->pushButton_2->setStyleSheet("QPushButton { font-size: 18pt; }");
     ui->pushButton_2->setText("Continue");
     bottomLayout->addWidget(ui->pushButton_2);
     connect(ui->pushButton_2, &QPushButton::clicked, this, &Song2::on_pushButton_2_clicked);

     // Tilføj bottomLayout til bunden af mainLayout
     mainLayout->addLayout(bottomLayout);

     // Sæt mainLayout som layout for denne dialog
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
      //  QSound::play("/home/stud/Desktop/NyBASGUI/NyGUI/NYGUI/SOSr/SOS/JB-ghost.wav");
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
            soundEffect = new QSound("/home/stud/Documents/NyBASGUI/NyGUI/NYGUI/SOSr/SOS/that-way.wav", this);
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



// Funktion til at fremhæve den aktuelle linje
void Song2::highlightCurrentLine(const QString &currentLine)
{
    qDebug() << "Highlighting line:" << currentLine;

        // Append the current line to the formatted text
        formattedText += "<span style='color: darkblue;'>" + currentLine + "</span><br/>";

        // Check if the current line is the end of a stanza
        if (currentLine.endsWith("know") || currentLine.endsWith("life")) {
            // Display the stanza and reset the formatted text
            ui->countdownLabel->setText(formattedText);
            formattedText.clear();
            qDebug() << "Displayed stanza.";
        }
}

// Funktion til at stoppe visning af teksten
void Song2::stopLyricsDisplay()
{
    if (lyricsTimer) {
            lyricsTimer->stop();
        }

        // Stop the sound using QSound
        if (soundEffect) {
            soundEffect->stop();
        }

        ui->countdownLabel->clear(); // Clear the text area when display stops
}

void Song2::on_pushButton_clicked() // Tilbage knap til songlist
{
    if (!songlist) {
        songlist = new SongList(this);
    }
    songlist->show();
    hide();
    stopLyricsDisplay();  // Stop the sound when the first button is clicked
}

void Song2::on_pushButton_2_clicked() {
    // Implement the logic to be executed when the second button is clicked
    if (!result) {
        result = new Results(this);
    }
    result->show();
    hide();
    stopLyricsDisplay();  // Stop the sound when the second button is clicked
    QSound::play("/dev/null");  // Play an empty sound to effectively stop any ongoing sound
}
