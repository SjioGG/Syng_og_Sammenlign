#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

// Base class
class Parse
{
public:
    virtual ~Parse() {}
    virtual void parseString(const string &input) = 0;
};

// Song class derived from Parse
class Song : public Parse
{
public:
    Song(int id) : id(id) {}
    ~Song() {}

    int id;
    string artist;
    string title;
    int duration;
    string key;
    string instrumental_file;
    string cmp_melody_file;
    string lyrics_file;

    void parseString(const string &input) override
    {
        stringstream ss(input);
        string token;

        getline(ss, token, '|');
        id = stoi(token);

        getline(ss, token, '|');
        artist = token;

        getline(ss, token, '|');
        title = token;

        getline(ss, token, '|');
        duration = stoi(token);

        getline(ss, token, '|');
        key = token;

        getline(ss, token, '|');
        instrumental_file = token;

        getline(ss, token, '|');
        cmp_melody_file = token;

        getline(ss, token, '|');
        lyrics_file = token;
    }
};

// Score class derived from Parse
class Score : public Parse
{
public:
    Score(int song_id) : song_id(song_id) {}
    ~Score() {}

    int id;
    int song_id;
    int score_value;
    string user;
    string date;

    void parseString(const string &input) override
    {
        stringstream ss(input);
        string token;

        getline(ss, token, '|');
        id = stoi(token);

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