// HighScore.cpp
#include "highscore.h"
#include "ui_highscore.h"
#include <algorithm> // For std::sort
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QString>

HighScore::HighScore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HighScore)
{
    ui->setupUi(this);

    // Testdata for spillere
    QVector<QPair<QString, int>> testHighscores;
    testHighscores.append(QPair<QString, int>("Spiller 1", 85));
    testHighscores.append(QPair<QString, int>("Spiller 2", 72));
    testHighscores.append(QPair<QString, int>("Spiller 3", 69));
    testHighscores.append(QPair<QString, int>("Spiller 4", 50));
    testHighscores.append(QPair<QString, int>("Spiller 5", 37));

    // Vis testdata ved at kalde funktionen
    showHighscores(testHighscores);

    // Opret knap til at gå tilbage til hovedmenuen
    QPushButton *backButton = new QPushButton("Tilbage til Hovedmenu", this);
    connect(backButton, &QPushButton::clicked, this, &HighScore::goBackToMainMenu);

    // Layout for knappen og highscoreLabell
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(ui->highscoreLabell);
    layout->addWidget(backButton);
    setLayout(layout);

    //Baggrunden - Lyseblå = 173, 216, 230.
    QPalette pal = palette();
    pal.setColor(QPalette::Window, QColor(173, 216, 230));
    setAutoFillBackground(true);
    setPalette(pal);

}

HighScore::~HighScore()
{
    delete ui;
}

void HighScore::showHighscores(const QVector<QPair<QString, int>>& newHighscores)
{
    // Kombiner de eksisterende highscores med de nye highscores
    QVector<QPair<QString, int>> combinedHighscores = highscoreData + newHighscores;

    // Sorter highscores i faldende rækkefølge baseret på score
    std::sort(combinedHighscores.begin(), combinedHighscores.end(), [](const QPair<QString, int>& a, const QPair<QString, int>& b) {
        return a.second > b.second;
    });

    // Begræns antallet af highscores til 5
    while (combinedHighscores.size() > 5) {
        combinedHighscores.pop_back();
    }

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

void HighScore::goBackToMainMenu()
{
    // Luk highscore-vinduet
    close();
}
