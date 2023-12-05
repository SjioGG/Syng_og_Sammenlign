// HighScore.cpp
#include "results.h"
#include "ui_results.h"
#include "song_list.h"
#include "mainwindow.h"
#include <algorithm> // For std::sort
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QString>

Results::Results(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Results),
    songlist(nullptr),
    menu(nullptr)
{
    ui->setupUi(this);
    this->showFullScreen();

}

Results::~Results()
{
    delete ui;
}

void Results::on_BackToMainMenu_clicked()
{
    if (!menu) {
        menu = new MainWindow(this);
    }
    menu->show();
    hide();
}


void Results::on_BackToSongList_clicked()
{
    if (!songlist) {
        songlist = new SongList(this);
    }
    songlist->show();
    hide();
}

// Definerer en funktion, Scoredisplay, som tager en sangs ID og bruger det til at vise scoren for den sang
void Results::ScoreDisplay(int song_id) {
// Antager at der findes en funktion, getScoreForSong, som kan hente en score baseret på en sangs ID
// Denne funktion er ikke vist her, men den vil hente scoren fra et sted i systemet
    Score score = getScoreForSong(song_id);

// Henter score værdien fra score objektet ved hjælp af en getter metode, getScoreValue
    int scoreValue = score.getScoreValue();

// Henter brugerens navn fra score objektet ved hjælp af en getter metode, getUser
    QString user = score.getUser();

// Henter datoen for scoren fra score objektet ved hjælp af en getter metode, getDate
    QString date = score.getDate();

    // Forbereder en tekststreng, der indeholder brugerens score, navn og datoen for scoren
    // %1, %2, og %3 er pladsholdere, der vil blive erstattet med score værdien, brugernavn og dato

    QString scoreText = QString("Score: %1\nUser: %2\nDate: %3")
                            .arg(scoreValue) // Erstatter %1 med score værdien
                            .arg(user)  // Erstatter %2 med brugernavn
                            .arg(date); // Erstatter %3 med dato
    ui->label->setText(scoreText);
  // Opdaterer teksten i QLabel (et GUI element) med navnet 'label' til at vise den forberedte tekststreng

}

