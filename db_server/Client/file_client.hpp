#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>






using namespace std;

#define STRING_SIZE 256

class ClientSocket
{
	fstream file;
	int port;
	int generalSocketDescriptor;
	struct sockaddr_in serverAddress;
	int addressLength;
	string SongString;
	string ScoreString;

public:
	ClientSocket(const char *ipStr)
	{
		port = 9000;
		serverAddress.sin_family = AF_INET;
		serverAddress.sin_port = htons(port);
		addressLength = sizeof(serverAddress);
		if (inet_pton(AF_INET, ipStr, &serverAddress.sin_addr) <= 0)
		{
			perror("ERROR: Invalid address");
			exit(1);
		}
	}

	~ClientSocket()
	{
		close(generalSocketDescriptor);
	}

	string getSongString()
	{
		return SongString;
	}

	string getScoreString()
	{
		return ScoreString;
	}

	void createSocket()
	{
		generalSocketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
		if (generalSocketDescriptor < 0)
		{
			perror("ERROR opening socket");
			exit(1);
		}
		printf("Socket created\n");
	}

	void connectToServer()
	{
		addressLength = sizeof(serverAddress);
		if (connect(generalSocketDescriptor, (struct sockaddr *)&serverAddress, addressLength) < 0)
		{
			perror("ERROR connecting");
			exit(1);
		}
		printf("Connected to server!\n");
	}

	void requestSongData(int data)
	{	
		string request = "GET_ALL_DATA," + to_string(data);
		char buffer[STRING_SIZE];
		strncpy(buffer, request.c_str(), STRING_SIZE - 1);
		buffer[STRING_SIZE - 1] = '\0';
		send(generalSocketDescriptor, buffer, STRING_SIZE, 0);
		
		char response[STRING_SIZE];
		recv(generalSocketDescriptor, response, STRING_SIZE, 0);
		SongString = response;
		cout << "song_result: " << SongString << endl;
		
		char response2[STRING_SIZE];
		recv(generalSocketDescriptor, response2, STRING_SIZE, 0);
		string instrumental_file = response2;
		receiveFile(instrumental_file);
		cout << "Instrumental: " << instrumental_file << endl;

		char response3[STRING_SIZE];
		recv(generalSocketDescriptor, response3, STRING_SIZE, 0);
		string melody_file = response3;
		receiveFile(melody_file);
		cout << "Melody: " << melody_file << endl;

		char response4[STRING_SIZE];
		recv(generalSocketDescriptor, response4, STRING_SIZE, 0);
		string lyrics_file = response4;
		receiveFile(lyrics_file);
		cout << "Lyrics: " << lyrics_file << endl;

		close(generalSocketDescriptor);
	}

	void addScoreToServer(int songId, int scoreValue, string user, string date)
	{
		string request = "ADD_SCORE," + to_string(songId);
		char buffer[STRING_SIZE];
		strncpy(buffer, request.c_str(), STRING_SIZE - 1);
		buffer[STRING_SIZE - 1] = '\0';
		send(generalSocketDescriptor, buffer, STRING_SIZE, 0); // +1 to include the null terminator
		// New row data
		string rowDataString = to_string(scoreValue) + "|" + user + "|" + date;
		char rowData[STRING_SIZE];
		strncpy(rowData, rowDataString.c_str(), STRING_SIZE - 1);
		rowData[STRING_SIZE - 1] = '\0';
		send(generalSocketDescriptor, rowData, STRING_SIZE, 0);
		cout << rowDataString << "C-string: " << rowDataString.c_str() << "size: "<< rowDataString.size() << "\n";
	}

	void requestScores(int songId)
	{
		char buffer[STRING_SIZE];
		string request = "SEND_SCORES,"+ to_string(songId);
		strncpy(buffer, request.c_str(), STRING_SIZE - 1);
		buffer[STRING_SIZE - 1] = '\0';
		send(generalSocketDescriptor, buffer, STRING_SIZE, 0);
	
		char response[2 * STRING_SIZE]; // edge case
		recv(generalSocketDescriptor, response, 2 * STRING_SIZE, 0);
		ScoreString = response;
		cout << "result: " << ScoreString << endl;
	}

	void receiveFile(string filename)
	{
		// Open the file to write to
		file.open((".//") + filename, ios::out | ios::trunc | ios::binary);
		if (file.is_open())
		{
			printf("File opened\n");
		}
		else
		{
			perror("ERROR: File not opened");
			exit(1);
		}
		// Receive the file size from the client
		uint32_t fileSizeNetworkOrder;
		if (recv(generalSocketDescriptor, &fileSizeNetworkOrder, sizeof(uint32_t), 0) < 0)
		{
			perror("Error: File size not received");
			exit(1);
		}
		uint32_t fileSize = ntohl(fileSizeNetworkOrder);
		printf("File size: %d\n", fileSize);
		printf("FSN: %u\n", fileSizeNetworkOrder);
		char buffer[1000];
		int totalBytesReceived = 0;
		int bytesInInterval = 0;
		int bytesRead;

		while (totalBytesReceived < fileSize)
		{
			bytesRead = recv(generalSocketDescriptor, buffer, sizeof(buffer), 0);

			if (bytesRead < 0)
			{
				perror("ERROR reading from socket");
				exit(1);
			}

			// Write to the file
			file.write(buffer, bytesRead);

			totalBytesReceived += bytesRead;
			bytesInInterval += bytesRead;

			// Print progress every 1000 bytes
			if (bytesInInterval >= 1000)
			{
				printf("Received %d bytes (%.2f%%)\n", totalBytesReceived, (static_cast<double>(totalBytesReceived) / fileSize) * 100);
				bytesInInterval = 0; // Reset the interval count
			}
		}

		printf("Received %d bytes (100.00%%)\n", totalBytesReceived); // Print the final progress
		file.close();

		// Send ACK
		char ack[3] = {"1\0"};
		send(generalSocketDescriptor, ack, sizeof(ack) - 1, 0);
	}
};