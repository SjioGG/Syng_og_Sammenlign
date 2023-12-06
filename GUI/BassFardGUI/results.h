// results.h
#ifndef RESULTS_H
#define RESULTS_H

#include <QDialog>
#include <QVector>
//#include "../../Score.h"


class MainWindow;
class SongList;
// class Score
namespace Ui {
class Results;
}

class Results : public QDialog
{
    Q_OBJECT

public:
    explicit Results(QWidget *parent = nullptr);
    ~Results();
    void ScoreDisplay(int song_id); // denne metoder fremviser scoren

private:
    Ui::Results *ui;
    QVector<QPair<QString, int>> highscoreData;  // Opbevar highscore-data som et QVector af QPair
    QString currentSong;
    SongList *songlist;
    MainWindow *menu;

private slots:
    void on_BackToMainMenu_clicked();
    void on_BackToSongList_clicked();
};

#endif // RESULTS_H
