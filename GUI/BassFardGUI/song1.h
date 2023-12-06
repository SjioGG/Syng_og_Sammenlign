// song1.h
#ifndef SONG1_H
#define SONG1_H

#include <QDialog>
#include <QTimer>
#include <QSound>

class SongList;
class Results;

namespace Ui {
class Song1;
}

class Song1 : public QDialog
{
    Q_OBJECT

public:
    explicit Song1(QWidget *parent = nullptr);
    ~Song1();

private slots:
    void on_pushButton_clicked();
    void updateCountdown();
    void on_pushButton_2_clicked();

private:
    Ui::Song1 *ui;
    int count_down_V;
    QTimer *count_down_T;
    SongList *songlist;
    void loadLyricsFromFile(const QString &filePath);
    QTimer *lyricsTimer;
    QStringList ghostLyrics;
    int lineCounter;
    Results *result;
    static QSound* soundEffect;
    QString formattedText;
    void startLyricsDisplay();
    void updateLyrics();
    void highlightCurrentLine(const QString &currentLine);
    void stopLyricsDisplay();

};

#endif // SONG1_H
