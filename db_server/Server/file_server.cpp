#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sqlite3.h>


using namespace std;
// #define STRBUFSIZE 256
class ServerSocket
{
	fstream file;
	int port;
	int generalSocketDescriptor;
	int newSocketDescriptor;
	struct sockaddr_in serverAddress;
	int adressLength;

public:
	ServerSocket()
	{
		port = 9000;
		serverAddress.sin_family = AF_INET;			// IPv4
		serverAddress.sin_addr.s_addr = INADDR_ANY; // any address
		serverAddress.sin_port = htons(port);		// host to network short
		adressLength = sizeof(serverAddress);		// set length of address
	}

	void createSocket()
	{
		if ((generalSocketDescriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		{
			perror("Error: Socket not created");
			exit(1);
		}
		else
		{
			printf("Socket created\n");
		}
	}

	void bindSocket()
	{
		if (bind(generalSocketDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
		{
			perror("Error: Socket not binded");
			exit(1);
		}
		else
		{
			printf("Socket binded\n");
		}
	}

	void listenSocket()
	{
		if (listen(generalSocketDescriptor, 5) < 0)
		{
			perror("Error: Socket not listening");
			exit(1);
		}
		else
		{
			printf("Socket listening\n");
		}
	}

	void acceptSocket()
	{
		if((newSocketDescriptor = accept(generalSocketDescriptor,(struct sockaddr *)&serverAddress,(socklen_t*)&adressLength)) < 0)
		{
			perror("Socket not accepted");
			exit(1);
		}
		else
		{
			printf("Socket accepted\n");
		}
	}

	void sendFile(const string filenamae)
	{
		// Open the corresponding file for sending based on the received filename.
		file.open(".//" + filenamae, ios::in | ios::binary);

		if (!file.is_open())
		{
			perror("Error: File not opened");
			exit(1);
		}
		// Calculate the size of the file
		file.seekg(0, ios::end);
		int fileSize = file.tellg();
		file.seekg(0, ios::beg);

		// Send the file size to the client
		int fileSizeNetworkOrder = htonl(fileSize);
		if (send(newSocketDescriptor, &fileSizeNetworkOrder, sizeof(fileSizeNetworkOrder), 0) < 0)
		{
			perror("Error: File size not sent");
			exit(1);
		}

		char buffer[1000]; // Buffer to read and send file in chunks
		int totalBytesSent = 0;
		int chunkNumber = 0;
		int bytesInInterval = 0;
		int bytesRead;

		while ((bytesRead = file.read(buffer, sizeof(buffer)).gcount()) > 0)
		{
			// Send the chunk over the socket
			if (send(newSocketDescriptor, buffer, bytesRead, 0) < 0)
			{
				perror("Error: File not sent");
				exit(1);
			}

			totalBytesSent += bytesRead;
			chunkNumber++;
			bytesInInterval += bytesRead;

			// Print progress every 1000 bytes
			if (bytesInInterval >= 1000)
			{
				printf("Sent %d bytes (%.2f%%)\n", totalBytesSent, (static_cast<double>(totalBytesSent) / fileSize) * 100);
				bytesInInterval = 0; // Reset the interval count
			}
		}

		// Close the file
		file.close();
		printf("Sent %d bytes (100.00%%)\n", totalBytesSent); // Print the final progress
	}

	void handleClient()
	{
    	char requestBuffer[256];
    	recv(newSocketDescriptor, requestBuffer, sizeof(requestBuffer), 0);
    	printf("Received request: %s\n", requestBuffer);

    	// Parse the request and extract request type and additional integer
    	std::string requestString(requestBuffer);
    	size_t commaPos = requestString.find(",");
    	if (commaPos != std::string::npos)
    	{
        	std::string requestType = requestString.substr(0, commaPos);
        	int additionalInt = -1;

        	try
        	{
            	additionalInt = std::stoi(requestString.substr(commaPos + 1));
        	}
        	catch (const std::exception &e)
        	{
            	// Handle the case where conversion to integer fails
            	std::cerr << "Error: Failed to parse additional integer\n";
        	}

        	// Now you can use 'requestType' and 'additionalInt' for further processing
        	if (requestType == "GET_ALL_DATA")
        	{
            	// Handle the request to send all data from the database
            	sendAllData(additionalInt);
        	}
        	else if (requestType == "ADD_SCORE")
        	{
            	// Handle the request to update the score table
            	addScore(additionalInt);
        	}
			else if (requestType == "SEND_SCORES")
        	{
            	// Handle the request to update the score table
            	sendScores(additionalInt);
        	}
        	else
        	{
            	// Unknown request type
            	perror("Error: Unknown request type");
            	exit(1);
    		}
    	}
    	else
    	{
        	// Handle the case where there is no comma in the request
        	perror("Error: Invalid request format");
        	exit(1);
    	}
	}

	void sendAllData(int songId)
	{
    	// Open the SQLite database
    	sqlite3 *db;
    	if (sqlite3_open("sos.db", &db) != SQLITE_OK)
    	{
        	perror("Error: Cannot open the database");
        	exit(1);
    	}

    	// Perform a query to get all data from the 'song' table
    	const char *query = "SELECT song.id, artist.name, song.title, song.duration, song.key, song.instrumental_file, song.cmp_melody_file, song.lyrics_file FROM song JOIN artist ON song.artist_id = artist.id WHERE song.id = ?";
    	sqlite3_stmt *statement;
    	if (sqlite3_prepare_v2(db, query, -1, &statement, nullptr) != SQLITE_OK)
    	{
        	perror("Error: Cannot prepare the query");
        	sqlite3_close(db);
        	exit(1);
    	}
		// Bind the parameter to the statement
		if (sqlite3_bind_int(statement, 1, songId) != SQLITE_OK)
		{
    		perror("Error: Cannot bind parameter");
    		exit(1);
		}

    	// Create a string to store the rJane esult
    	std::string result;
		std::string instrumental_file;
		std::string melody_file;
		std::string lyrics_file;

    	// Fetch data from the query and append it to the string
    	while (sqlite3_step(statement) == SQLITE_ROW)
    	{
        	// Fetch each column's data
        	int songId = sqlite3_column_int(statement, 0);
        	const char *artistName = reinterpret_cast<const char *>(sqlite3_column_text(statement, 1));
        	const char *title = reinterpret_cast<const char *>(sqlite3_column_text(statement, 2));
        	int duration = sqlite3_column_int(statement, 3);
        	const char *key = reinterpret_cast<const char *>(sqlite3_column_text(statement, 4));
        	const char *instrumentalFile = reinterpret_cast<const char *>(sqlite3_column_text(statement, 5));
        	const char *melodyFile = reinterpret_cast<const char *>(sqlite3_column_text(statement, 6));
        	const char *lyricsFile = reinterpret_cast<const char *>(sqlite3_column_text(statement, 7));

        	// Construct a string with the fetched data and append it to the result
        	result += std::to_string(songId) + "|" + artistName + "|" + title + "|" + std::to_string(duration) + "|" + key + "|" + instrumentalFile + "|" + melodyFile + "|" + lyricsFile + "\n";
			
			// For file transfer (Bring them out of this scope)
			instrumental_file = instrumentalFile;
			melody_file = melodyFile;
			lyrics_file = lyricsFile;
		}

    	// Clean up
    	sqlite3_finalize(statement);
    	sqlite3_close(db);

    	// Send the combined data to the client
    	send(newSocketDescriptor, result.c_str(), result.size(), 0);
		sleep(1);
		send(newSocketDescriptor, instrumental_file.c_str(), result.size(), 0);
		sendFile(instrumental_file);
		sleep(1);	
		send(newSocketDescriptor, melody_file.c_str(), result.size(), 0);
		sendFile(melody_file);
		sleep(1);
		send(newSocketDescriptor, lyrics_file.c_str(), result.size(), 0);
        sendFile(lyrics_file);
    	printf("Sent all data to the client\n");
	}

    void addScore(int songId)
    {
        // Implement logic to update the score table in the database
        // ... SQL stuff

        // For now, let's just send a sample response
        char responseData[256] = "Score updated successfully";
        send(newSocketDescriptor, responseData, strlen(responseData), 0);

        printf("Score updated\n");
    }

	void sendScores(int songId)
	{

	}

};

int main(int argc, char *argv[])
{
	printf("Starting server...\n");
	ServerSocket server;
	server.createSocket();
	server.bindSocket();
	while (1)
	{
		server.listenSocket();
		server.acceptSocket();
		server.handleClient();
		//server.sendFile(); 	// ->  server.handleClient();
							// will either recieve or send data,
							// depending on the client's request.
							// Probably either "add a row" or "send all data"
	}
	return 0;
}