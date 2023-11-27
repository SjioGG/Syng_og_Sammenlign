#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

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

	// void acceptSocket()
	// {
	// 	if ((newSocketDescriptor = accept(generalSocketDescriptor, (struct sockaddr *)&serverAddress, (socklen_t *)&adressLength)) < 0)
	// 	{
	// 		perror("Error: Socket not accepted");
	// 		exit(1);
	// 	}
	// 	else
	// 	{
	// 		printf("Socket accepted\n");
	// 	}

	// 	char filenameBuffer[256]; // Adjust the buffer size as needed
	// 	recv(newSocketDescriptor, filenameBuffer, sizeof(filenameBuffer), 0);
	// 	printf("Received filename: %s\n", filenameBuffer);

	// 	std::string filename(filenameBuffer);

	// 	// Now, you have the filename in the `filename` string.

	// 	// Open the corresponding file for sending based on the received filename.
	// 	file.open(".//datatosend//" + filename, ios::in | ios::binary);

	// 	if (!file.is_open())
	// 	{
	// 		perror("Error: File not opened");
	// 		char failed[256] = "Requested file does not exist";
	// 		exit(1);
	// 		send(newSocketDescriptor, failed, sizeof(failed), 0);
	// 	}
	// 	else
	// 	{
	// 		char notfailed[256] = "shit good";
	// 		send(newSocketDescriptor, notfailed, sizeof(notfailed), 0);
	// 		printf("File opened\n");
	// 	}

	// 	sleep(0.29);
	// }

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

	void sendFile()
	{
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

		// Close the socket
		// close(newSocketDescriptor);
		printf("Sent %d bytes (100.00%%)\n", totalBytesSent); // Print the final progress
	}

	void handleClient()
    {
        char requestTypeBuffer[256];
        recv(newSocketDescriptor, requestTypeBuffer, sizeof(requestTypeBuffer), 0);
        printf("Received request type: %s\n", requestTypeBuffer);

        // Handle different request types
        if (strcmp(requestTypeBuffer, "GET_ALL_DATA") == 0)
        {
            // Handle the request to send all data from the database
            sendAllData();
        }
        else if (strcmp(requestTypeBuffer, "UPDATE_SCORE") == 0)
        {
            // Handle the request to update the score table
            updateScore();
        }
        else
        {
            // Unknown request type
            perror("Error: Unknown request type");
            exit(1);
        }
    }

	void sendAllData()
    {
        // Implement logic to retrieve data from the database and send it to the client
        // ... SQL stuff

        // For now, let's just send a sample response
        char responseData[256] = "Sample data from the server";
        send(newSocketDescriptor, responseData, strlen(responseData), 0);

        printf("Sent all data to the client\n");
    }

    void updateScore()
    {
        // Implement logic to update the score table in the database
        // ... SQL stuff

        // For now, let's just send a sample response
        char responseData[256] = "Score updated successfully";
        send(newSocketDescriptor, responseData, strlen(responseData), 0);

        printf("Score updated\n");
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