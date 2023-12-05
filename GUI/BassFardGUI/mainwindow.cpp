// MainWindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "song_list.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include "highscore.h"
#include "song_list.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), songs(nullptr), highScoreDialog(nullptr)
{
    ui->setupUi(this);
    this->showFullScreen();

    QLabel *titleLabel = new QLabel("Welcome to SOS Karaoke", this);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(24);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(ui->pushButton);
    mainLayout->addWidget(ui->pushButton_2);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

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

    // Opret highScoreDialog
    highScoreDialog = new HighScore(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    songs = new SongList(this);
    songs->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    highScoreDialog->show();
}
