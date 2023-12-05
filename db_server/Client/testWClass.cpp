#include "SongScoreCombined.hpp"
#include <unistd.h>

int main()
{
    // SONG CLASS TEST
    Song song(1);
    string songString = song.getData(1);
    cout << "OG STRING:    " << songString << endl;
    song.parseString(songString);
    cout << "ARTIST:       " << song.getArtist() << endl;
    cout << "TITLE:        " << song.getTitle() << endl;
    cout << "LENGTH:       " << song.getDuration() << endl;
    cout << "KEY:          " << song.getKey() << endl;
    cout << "INSTRUMENTAL: " << song.getInstrumentalFile() << endl;
    cout << "MELODY:       " << song.getCmpMelodyFile() << endl;
    cout << "LYRICS:       " << song.getLyricsFile() << endl;

    // SCORE CLASS TEST
    ScoreList scoreList;
    string scoreString = scoreList.getData(1);

    cout << "OG STRING:    " << scoreString << endl;
    scoreList.parseString(scoreString);
    cout << "ScoreList:" << "\n" << scoreList << endl;

    // fx access variables
    vector<Score> top10 = scoreList.getScores();
    cout << top10[1].getScoreValue() << endl;
    
    // TEST ADD FUNCTION
    Score score;
    score.addScore(1, 9000, "Boobman69", "2011-11-11");
    return 0;
}