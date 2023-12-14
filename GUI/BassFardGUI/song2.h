// song2.h
#ifndef SONG2_H
#define SONG2_H

#include <QDialog>
#include <QTimer>
#include <QSound>
#include "./../../db_server/Client/Song.hpp"

class SongList;
class Results;

namespace Ui {
class Song2;
}

class Song2 : public QDialog
{
    Q_OBJECT

public:
    explicit Song2(QWidget *parent = nullptr);
    ~Song2();

private slots:
    void on_pushButton_clicked();
    void updateCountdown();

    void on_pushButton_2_clicked();

private:
    Ui::Song2 *ui;
    int count_down_V;
    QTimer *count_down_T;
    SongList *songlist; // Ensure you have forward declared SongList if necessary
    void loadLyricsFromFile(const QString &filePath);
    QTimer *lyricsTimer;
    QStringList ghostLyrics;
    int lineCounter;
    Results *result;
    QSound* soundEffect;
    QString formattedText;
    void startLyricsDisplay();
    void updateLyrics();
    void highlightCurrentLine(const QString &currentLine);
    void stopLyricsDisplay();
    Song song;
};

#endif // SONG2_H
