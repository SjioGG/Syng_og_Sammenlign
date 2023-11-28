#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Song
{
public:
    Song(int id) : id(id){};
    ~Song(){};
    int id;
    string artist;
    string title;
    int duration;
    string key;
    string instrumental_file;
    string cmp_melody_file;
    string lyrics_file;

    void parseString(const string &input) // input: "id|artist|title|duration|key|instrumental_file|cmp_melody_file|lyrics_file"
    {
        stringstream ss(input);
        string token;

        getline(ss, token, '|'); // getline: read a line from a stream
        id = stoi(token);        // stoi: string to int

        getline(ss, token, '|');
        artist = token;

        getline(ss, token, '|');
        title = token;

        getline(ss, token, '|');
        duration = stoi(token); // stoi: string to int

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