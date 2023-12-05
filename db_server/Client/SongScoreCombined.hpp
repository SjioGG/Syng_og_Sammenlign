#include <string>
#include <iostream>
#include <sstream>
#include "file_client.hpp"
#include <vector>
using namespace std;

// Base class
class Parse
{
public:
    virtual ~Parse() {}
    virtual void parseString(const string &input) = 0;
    virtual string getData(int id) = 0;
};

// Song class derived from Parse
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
        ClientSocket clientSocket("10.0.0.1");
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

// Score class derived from Parse
class Score : Parse
{

private:
    int id_;
    int song_id_;
    int score_value_;
    string user_;
    string date_;

public:
    Score(int song_id = -1) : song_id_(song_id) {}
    ~Score() {}
    int getId() { return id_; }
    int getSongId() { return song_id_; }
    int getScoreValue() { return score_value_; }
    string getUser() { return user_; }
    string getDate() { return date_; }

    string getData(int id) override {return "invalid";}

    void parseString(const string &input) override
    {
        stringstream ss(input);
        string token;

        getline(ss, token, '|');
        id_ = stoi(token);

        getline(ss, token, '|');
        song_id_ = stoi(token);

        getline(ss, token, '|');
        score_value_ = stoi(token);

        getline(ss, token, '|');
        user_ = token;

        getline(ss, token, '|');
        date_ = token;
    }

    void addScore(int songId, int scoreValue, string user, string date)
    {
        ClientSocket clientSocket("10.0.0.1");
        clientSocket.createSocket();
        clientSocket.connectToServer();
        clientSocket.addScoreToServer(songId, scoreValue, user, date);
    }

    // Declare friend operator<< to allow it to access private members
    friend std::ostream &operator<<(std::ostream &os, const Score &score);
};

// Define the operator<< for Score
std::ostream &operator<<(std::ostream &os, const Score &score) 
{
    os << "ID: " << score.id_ << " Song ID: " << score.song_id_ 
       << " Score: " << score.score_value_ << " User: " << score.user_ 
       << " Date: " << score.date_;
    return os;
}

class ScoreList : public Parse
{
private:
    vector<Score> scores_;


public:
    void parseString(const string &input) override
    {
        stringstream ss(input);
        string scoreString;

        while (getline(ss, scoreString, ',')) // parse the string from the server with "," as a delimiter
        {
            Score score;                 // create a score object
            score.parseString(scoreString); // parse the string from the server
            scores_.push_back(score);        // add the score object to the vector
        }
        scores_.pop_back(); // remove the last element of the vector
    }

    string getData(int id) override
    {
        ClientSocket clientSocket("10.0.0.1");
        clientSocket.createSocket();
        clientSocket.connectToServer();
        clientSocket.requestScores(id);

        string scoreString = clientSocket.getScoreString();
        parseString(scoreString); // Score object parses the string from the server
        return scoreString;
    }

    const vector<Score> &getScores() const // returns a vector of all the scores
    {
        return scores_;
    }

    friend std::ostream &operator<<(std::ostream &os, const ScoreList &scoreList);
};

// Define the operator<< for ScoreList
std::ostream &operator<<(std::ostream &os, const ScoreList &scoreList) 
{
    for (const auto &score : scoreList.getScores()) {  // Use the public getter method
        os << score << std::endl;  // Utilize the already defined operator<< for Score
    }
    return os;
}