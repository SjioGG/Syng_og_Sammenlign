#include "SongScoreCombined.hpp"
#include <unistd.h>

int main()
{
    // SONG CLASS TEST
    Song song(1);
    string songString = song.getData();
    cout << "OG STRING:    "<< songString << endl;
    song.parseString(songString);
    cout << "ARTIST:       " <<song.artist << endl;
    cout << "TITLE:        "<<song.title << endl;
    cout << "LENGTH:       " <<song.duration << endl;
    cout << "KEY:          " <<song.key << endl;
    cout << "INSTRUMENTAL: " <<song.instrumental_file << endl;
    cout << "MELODY:       " <<song.cmp_melody_file << endl;
    cout << "LYRICS:       " <<song.lyrics_file << endl;

    //sleep(1);
    // SCORE CLASS TEST
    Score score(1);
    string scoreString = score.getData();
    cout << "OG STRING:    "<< scoreString << endl;
    score.parseString(scoreString);
    cout << "SCORE ID:     "<< score.id << endl;
    cout << "SONG ID:      " <<score.song_id << endl;
    cout << "USER:         "<<score.user << endl;
    cout << "SCORE:        " << score.score_value << endl;
    cout << "DATE:         " << score.date << endl;
    //sleep(1);
    // TEST ADD FUNCTION
    score.addScore(1, 9000, "Boobman69", "2011-11-11");
    return 0;
}