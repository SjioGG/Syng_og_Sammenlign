#include <iostream>
#include "Score.h"

int main()
{
    // Create a Song object
    Score userScore(1);

    // Provide a sample string
    string inputString = "1|1|100|user1|28-11-2023";

    // Call the parseString method to parse the string
    userScore.parseString(inputString);

    // Display the parsed information using the pointer
    cout << "ID: " << userScore.id << endl;
    cout << "Song id: " << userScore.song_id << endl;
    cout << "Score value: " << userScore.score_value << endl;
    cout << "User: " << userScore.user << endl;
    cout << "Date: " << userScore.date << endl;

    return 0;
}