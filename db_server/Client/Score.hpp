#ifndef SCORE_HPP
#define SCORE_HPP

#include "Parse.hpp"

class Score : public Parse
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

    // This was excluded, since the scope of the project changed.
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
        ClientSocket clientSocket;
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

#endif