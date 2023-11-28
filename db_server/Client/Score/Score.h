#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Score
{
public:
    Score(int song_id) : song_id(song_id){};
    ~Score(){};
    void addScore(int score);

    int id;
    int song_id;
    int score_value;
    string user;
    string date;

    void parseString(const string &input) // input: "id|song_id|score_value|user|date"
    {
        stringstream ss(input);
        string token;

        getline(ss, token, '|'); // getline: read a line from a stream
        id = stoi(token);        // stoi: string to int

        getline(ss, token, '|');
        song_id = stoi(token);

        getline(ss, token, '|');
        score_value = stoi(token);

        getline(ss, token, '|');
        user = token;

        getline(ss, token, '|');
        date = token;
    }
};