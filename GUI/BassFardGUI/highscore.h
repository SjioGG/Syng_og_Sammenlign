// HighScore.h
#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QDialog>
#include <QVector>

namespace Ui {
class HighScore;
}

class HighScore : public QDialog
{
    Q_OBJECT

public:
    explicit HighScore(QWidget *parent = nullptr);
    ~HighScore();

    // Funktion til at indstille highscores
    void showHighscores(const QVector<QPair<QString, int>>& highscores);

private:
    Ui::HighScore *ui;
    QVector<QPair<QString, int>> highscoreData;  // Opbevar highscore-data som et QVector af QPair
    QString currentSong;

public slots:
    void goBackToMainMenu();

};

#endif // HIGHSCORE_H
