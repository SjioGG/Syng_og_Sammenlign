#include <iostream>
#include "Song.h"

int main()
{
    // Create a Song object
    Song mySong(1);

    // Provide a sample string
    string inputString = "1|Justin Bieber|Ghost|240|C|instrumental1.mp3|melody1.mp3|lyrics1.txt";

    // Call the parseString method to parse the string
    mySong.parseString(inputString);

    // Display the parsed information using the pointer
    cout << "ID: " << mySong.id << endl;
    cout << "Artist: " << mySong.artist << endl;
    cout << "Title: " << mySong.title << endl;
    cout << "Duration: " << mySong.duration << endl;
    cout << "Key: " << mySong.key << endl;
    cout << "Instrumental File: " << mySong.instrumental_file << endl;
    cout << "Melody File: " << mySong.cmp_melody_file << endl;
    cout << "Lyrics File: " << mySong.lyrics_file << endl;

    return 0;
}