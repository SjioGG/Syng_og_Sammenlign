#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QDialog>
#include <QVector>

class MainWindow;

namespace Ui {
class HighScore;
}

class HighScore : public QDialog
{
    Q_OBJECT

public:
    explicit HighScore(QWidget *parent = nullptr);
    ~HighScore();
    void showHighscores(const QVector<QPair<QString, int>>& highscores);

private:
    Ui::HighScore *ui;
    QVector<QPair<QString, int>> highscoreData;  // Opbevar highscore-data som et QVector af QPair
    QString currentSong;
    MainWindow *menu;

private slots:
    void on_pushButton_clicked();
};

#endif // HIGHSCORE_H
