#pragma once
#include <string>
#include <iostream>
using namespace std;

class Score
{
private:
    int id;
    int song_id;
    int score_value;
    string user;
    string date;

public:
    Score(int song_id);
    ~Score(){};
    void addScore(int score);
};