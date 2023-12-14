#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "song_list.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include "highscore.h"
#include "song_list.h"

// Konstruktør for MainWindow-klassen
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow),
    songs(nullptr),
    highScoreDialog(nullptr)
{
    // Initialiserer brugergrænsefladen ved at kalde Ui_mainwindow's setupUi-funktion
    ui->setupUi(this);

    // Viser MainWindow i fuldskærmstilstand
    this->showFullScreen();

    // Opretter en QLabel med en velkomstbesked og konfigurerer dens udseende
    QLabel *titleLabel = new QLabel("Welcome to SOS Karaoke", this);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(24);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);

    // Opretter et QVBoxLayout til layoutet af MainWindow
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(titleLabel);           // Tilføjer overskriftsetiketten til layoutet
    mainLayout->addWidget(ui->pushButton);       // Tilføjer knappen med teksten "Start" til layoutet
    mainLayout->addWidget(ui->pushButton_2);     // Tilføjer knappen med teksten "High Scores" til layoutet

    // Opretter et centralt widget og tildeles det oprettede layout
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);  // Sætter det centrale widget som centrum for MainWindow

    // Konfigurerer stilen for knapperne ved hjælp af CSS
    QString buttonStyle = "QPushButton {"
                          "background-color: #445566;"
                          "color: white;"
                          "border-radius: 5px;"
                          "padding: 10px;"
                          "font-size: 16px;"
                          "font-weight: bold;"
                          "} "
                          "QPushButton:hover {"
                          "background-color: #667788;"
                          "}";
    setStyleSheet(buttonStyle);

    // Opretter et HighScore-dialogvindue og tildeler det MainWindow som overordnet widget
    highScoreDialog = new HighScore(this);
}

// Destruktør for MainWindow-klassen
MainWindow::~MainWindow()
{
    delete ui;  // Frigiver ressourcer allokeret til brugergrænsefladeobjektet
}

// Event handler for "Start" knappen
void MainWindow::on_pushButton_clicked()
{
    hide();         // Skjuler MainWindow-vinduet
    songs = new SongList(this);  // Opretter et nyt SongList-objekt
    songs->show();  // Viser SongList-vinduet
}

// Event handler for "High Scores" knappen
void MainWindow::on_pushButton_2_clicked()
{
    hide();                          // Skjuler MainWindow-vinduet
    highScoreDialog = new HighScore(this);  // Opretter et nyt HighScore-objekt
    highScoreDialog->show();          // Viser HighScore-dialogvinduet
}
