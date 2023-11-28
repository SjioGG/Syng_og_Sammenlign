#include <iostream>
#include "Song.h"

int main()
{
    // Create a Song object
    Song mySong(1);

    // Provide a sample string
    std::string inputString = "1|Justin Bieber|Ghost|240|C|instrumental1.mp3|melody1.mp3|lyrics1.txt";

    // Call the parseString method to parse the string
    mySong.parseString(inputString);

    // Display the parsed information using the pointer
    std::cout << "ID: " << mySong.id << std::endl;
    std::cout << "Artist: " << mySong.artist << std::endl;
    std::cout << "Title: " << mySong.title << std::endl;
    std::cout << "Duration: " << mySong.duration << std::endl;
    std::cout << "Key: " << mySong.key << std::endl;
    std::cout << "Instrumental File: " << mySong.instrumental_file << std::endl;
    std::cout << "Melody File: " << mySong.cmp_melody_file << std::endl;
    std::cout << "Lyrics File: " << mySong.lyrics_file << std::endl;

    return 0;
}