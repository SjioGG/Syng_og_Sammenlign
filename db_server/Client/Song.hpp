#ifndef SONG_HPP
#define SONG_HPP

#include "Parse.hpp"
class Song : public Parse
{

private:
    int id_;
    string artist_;
    string title_;
    int duration_;
    string key_;
    string instrumental_file_;
    string cmp_melody_file_;
    string lyrics_file_;

public:
    Song(int id) : id_(id) {}
    ~Song() {}
    int getId() { return id_; }
    string getArtist() { return artist_; }
    string getTitle() { return title_; }
    int getDuration() { return duration_; }
    string getKey() { return key_; }
    string getInstrumentalFile() { return instrumental_file_; }
    string getCmpMelodyFile() { return cmp_melody_file_; }
    string getLyricsFile() { return lyrics_file_; }

    string getData(int id) override
    {
        ClientSocket clientSocket;
        clientSocket.createSocket();
        clientSocket.connectToServer();
        clientSocket.requestSongData(id);
        string songString = clientSocket.getSongString();
        return songString;
    }

    void parseString(const string &input) override
    {
        stringstream ss(input);
        string token;

        getline(ss, token, '|');
        id_ = stoi(token);

        getline(ss, token, '|');
        artist_ = token;

        getline(ss, token, '|');
        title_ = token;

        getline(ss, token, '|');
        duration_ = stoi(token);

        getline(ss, token, '|');
        key_ = token;

        getline(ss, token, '|');
        instrumental_file_ = token;

        getline(ss, token, '|');
        cmp_melody_file_ = token;

        getline(ss, token, '|');
        lyrics_file_ = token;
    }
};

#endif