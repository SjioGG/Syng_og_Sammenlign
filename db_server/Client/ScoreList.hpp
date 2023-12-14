#ifndef SCORELIST_HPP
#define SCORELIST_HPP
#include "Score.hpp"
#include <vector>

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
    }

    string getData(int id) override
    {
        ClientSocket clientSocket;
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

#endif