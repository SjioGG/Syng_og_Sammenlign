#include <string>
#include <iostream>
#include <sstream>
#include "file_client.hpp"
using namespace std;

// Base class
class Parse
{
public:
    virtual ~Parse() {}
    virtual void parseString(const string &input) = 0;
    virtual string getData() = 0;
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

    string getData() override
    {
        ClientSocket clientSocket("10.0.0.1");
        clientSocket.createSocket();
        clientSocket.connectToServer();
        clientSocket.requestSongData(id);
        // prob delay
        string songString = clientSocket.getSongString();
        return songString;
    }

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

    string getData() override
    {
        ClientSocket clientSocket("10.0.0.1");
        clientSocket.createSocket();
        clientSocket.connectToServer();
        clientSocket.requestScores(song_id);
        // prob delay
        string scoreString = clientSocket.getScoreString();
        return scoreString;
    }
    
    void addScore(int songId, int scoreValue, string user, string date)
    {
        ClientSocket clientSocket("10.0.0.1");
        clientSocket.createSocket();
        clientSocket.connectToServer();
        clientSocket.addScoreToServer(songId, scoreValue, user, date);
    }

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