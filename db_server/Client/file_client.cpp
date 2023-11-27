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

class ClientSocket
{
	fstream file;
	int port;
	int generalSocketDescriptor;
	struct sockaddr_in serverAddress;
	int addressLength;
	string fileName;

public:
	ClientSocket(const char *ipStr /*, std::string fileName*/)
	{
		port = 9000;
		// this->fileName = fileName;
		serverAddress.sin_family = AF_INET;
		serverAddress.sin_port = htons(port);
		addressLength = sizeof(serverAddress);
		if (inet_pton(AF_INET, ipStr, &serverAddress.sin_addr) <= 0)
		{
			perror("ERROR: Invalid address");
			exit(1);
		}
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

	// void requestFileFromServer() // Fix with send and recv, but problem with progress print
	// {
	// 	char filenameBuffer[256];
	// 	// Send the filename to the server as a request
	// 	send(generalSocketDescriptor, fileName.c_str(), sizeof(filenameBuffer), 0);
	// 	char response[256];
	// 	int bytesRead = recv(generalSocketDescriptor, response, sizeof(response), 0);
	// 	char failed[256] = "Requested file does not exist";
	// 	if (strcmp(response, failed) == 0)
	// 	{
	// 		printf("File not available or unexpected response from server: %s\n", response);
	// 		exit(1);
	// 	}
	// 	else
	// 	{
	// 		printf("File found!: %s\n", response);
	// 	}
	// }

	void requestAllData()
	{
		char request[256] = "GET_ALL_DATA";
		// Send the filename to the server as a request
		send(generalSocketDescriptor, request, sizeof(request), 0);
		char response[256];
		int bytesRead = recv(generalSocketDescriptor, response, sizeof(response), 0);
		// ERROR HANDLING LATER

		printf("data: %s\n", response);
	}
	void updateScore()
	{
		char request[256] = "UPDATE_SCORE";
		// Send the filename to the server as a request
		send(generalSocketDescriptor, request, sizeof(request), 0);
		char response[256];
		int bytesRead = recv(generalSocketDescriptor, response, sizeof(response), 0);
		// ERROR HANDLING LATER

		printf("data: %s\n", response);
	}

	void receiveFile()
	{
		// Open the file to write to
		file.open((".//datarecive//") + fileName, ios::out | ios::trunc | ios::binary);
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
		int fileSizeNetworkOrder;
		if (recv(generalSocketDescriptor, &fileSizeNetworkOrder, sizeof(fileSizeNetworkOrder), 0) < 0)
		{
			perror("Error: File size not received");
			exit(1);
		}
		int fileSize = ntohl(fileSizeNetworkOrder);

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
		close(generalSocketDescriptor);
	}
};

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <IP address> <filename>" << std::endl;
		return 1;
	}
	const char *ipStr = argv[1];
	// const char *filename = argv[2];

	std::cout << "Starting client with IP address: " << ipStr << std::endl;
	// Now you can use the 'serverAddress' struct and 'filename' to create the ClientSocket.
	ClientSocket clientSocket(ipStr);
	clientSocket.createSocket();
	clientSocket.connectToServer();
	clientSocket.requestAllData();
	// clientSocket.requestFileFromServer();
	// clientSocket.receiveFile();

	return 0;
}
