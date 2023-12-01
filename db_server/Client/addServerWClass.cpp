#include "file_client.hpp"

int main()
{
    const char* ipStr = "10.0.0.1";
	std::cout << "Starting client with IP address: " << ipStr << std::endl;
	// Now you can use the 'serverAddress' struct and 'filename' to create the ClientSocket.
	ClientSocket clientSocket(ipStr);
	clientSocket.createSocket();
	clientSocket.connectToServer();
	//clientSocket.requestScores(1);
	//clientSocket.requestSongData(2);
	clientSocket.addScoreToServer(1, 9000, "newUser", "newDate");
	// clientSocket.requestFileFromServer();
	// clientSocket.receiveFile();

	return 0;
}