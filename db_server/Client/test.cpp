#include "file_client.hpp"

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
	//clientSocket.requestScores(1);
	//clientSocket.requestSongData(2);
	clientSocket.addScoreToServer(1, 9000, "newUser", "newDate");
	// clientSocket.requestFileFromServer();
	// clientSocket.receiveFile();

	return 0;
}