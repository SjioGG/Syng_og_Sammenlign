// HighScore.cpp

// Inkluder nødvendige headerfiler og biblioteker
#include "highscore.h"
#include "ui_highscore.h"
#include "mainwindow.h"
#include <algorithm> // For std::sort
#include <iostream>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QString>
#include "./../../db_server/Client/Score.hpp"
#include "./../../db_server/Client/ScoreList.hpp"

// Konstruktør
HighScore::HighScore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HighScore),
    menu(nullptr)
{
    ui->setupUi(this);

    // Hent highscores fra ScoreList
    ScoreList scoreList;
    scoreList.getData(1);

    QVector<QPair<QString, int>> testHighscores;
    vector<Score> Top10 = scoreList.getScores();

    // Begræns antallet af highscores til 5
    for(int i = 0; i < 5; i++ ) {
        std::string fp = Top10[i].getUser();
        QString qstring_fp = QString::fromStdString(fp);
        testHighscores.append(QPair<QString, int>(qstring_fp, Top10[i].getScoreValue()));
    }

    // Vis testdata ved at kalde funktionen
    showHighscores(testHighscores);

    // Testdata for spillere hardcoded
    //testHighscores.append(QPair<QString, int>("Spiller 1", 85));
    //testHighscores.append(QPair<QString, int>("Spiller 2", 72));
    //testHighscores.append(QPair<QString, int>("Spiller 3", 69));
    //testHighscores.append(QPair<QString, int>("Spiller 4", 50));
    //testHighscores.append(QPair<QString, int>("Spiller 5", 37));

    // Opret knap til at gå tilbage til hovedmenuen
    QPushButton *on_pushButton_clicked = new QPushButton("Tilbage til Hovedmenu", this);
    connect(on_pushButton_clicked, &QPushButton::clicked, this, &HighScore::on_pushButton_clicked);

    // Layout for knappen og highscoreLabell
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(ui->highscoreLabell);
    layout->addWidget(on_pushButton_clicked);
    setLayout(layout);

    // Baggrunden - Lyseblå = 173, 216, 230.
    QPalette pal = palette();
    pal.setColor(QPalette::Window, QColor(173, 216, 230));
    setAutoFillBackground(true);
    setPalette(pal);

    // Vis testdata ved at kalde funktionen
    showHighscores(testHighscores);
}

// Destruktør
HighScore::~HighScore()
{
    delete ui;
}

// Funktion til at vise highscores på UI
void HighScore::showHighscores(const QVector<QPair<QString, int>>& newHighscores)
{
    // Kombiner de eksisterende highscores med de nye highscores
    QVector<QPair<QString, int>> combinedHighscores = highscoreData + newHighscores;

    // Sorter highscores i faldende rækkefølge baseret på score
    std::sort(combinedHighscores.begin(), combinedHighscores.end(), [](const QPair<QString, int>& a, const QPair<QString, int>& b) {
        return a.second > b.second;
    });

    // Opdater highscoreData med de nye highscores
    highscoreData = combinedHighscores;

    // Opret besked for alle spillere
    QString message = "<span style='font-size: 72px; color: red;'><b>Highscores:</b></span><br><br>";

    for (const auto& highscore : highscoreData) {
        message += "<span style='font-size: 36px;'><b>" + highscore.first + ":</b> " + QString::number(highscore.second) + "</span><br>";
    }

    // Opdater UI-elementer med highscore-data
    ui->highscoreLabell->setText(message);

    // Indstil størrelsen af dialogvinduet til fuld skærm
    setWindowState(Qt::WindowFullScreen);
}

// Funktion til at håndtere knaptryk for at gå tilbage til hovedmenuen
void HighScore::on_pushButton_clicked()
{
    // Opret et nyt MainWindow-vindue, hvis det ikke allerede eksisterer
    if (!menu) {
        menu = new MainWindow(this);
    }

    menu->show();
    hide();
}
