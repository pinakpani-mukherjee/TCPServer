#include <iostream>
#include <WS2tcpip.h>

#pragma (lib,"ws2_32.lib")

void main() {

	// Initialize winsock
	WSADATA  wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsOK = WSAStartup(ver, &wsData);
	if (wsOK != 0) {
		std::cerr << "Can't Initialize winsock! Quitting" << std::endl;
		return;
	}
	// Create a socket
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET) {
		std::cerr << "Cant create Socket! Quitting" << std::endl;
	}
	// Bind socket to ip address and port
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = INADDR_ANY;// Could also use inet_pton ...

	bind(listening, (sockaddr *)&hint, sizeof(hint));

	// Tell winsock the socket is for listening

	listen(listening, SOMAXCONN);


	// Wait for a connection

	sockaddr_in client;

	int clientSize = sizeof(client);

	SOCKET clientSocket = accept(listening,(sockaddr*)&client, &clientSize);

	char host[NI_MAXHOST]; // Client's remote name
	char service[NI_MAXHOST]; // Service port of the connected client

	ZeroMemory(host, NI_MAXHOST); //same as memset(host,0,NI_MAXHOST);
	ZeroMemory(service, NI_MAXHOST);



	// Close listening socket

	// While loop: accept and echo message back to client

	// Close the socket

	// Shutdown winsock
 
}