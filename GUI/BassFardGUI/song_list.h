#ifndef SONG_LIST_H
#define SONG_LIST_H

#include <QDialog>

class MainWindow;
class Song1;
class Song2;
namespace Ui {
class SongList;
}

class SongList : public QDialog
{
    Q_OBJECT

public:
    explicit SongList(QWidget *parent = nullptr);
    ~SongList();

private slots:
    void on_Song_2_clicked();
    void on_Song_1_clicked();
    void on_pushButton_clicked();

private:
    Ui::SongList *ui;
    MainWindow *mainmeny;
    Song1 *song1;
    Song2 *song2;
};

#endif // SONG_LIST_H
