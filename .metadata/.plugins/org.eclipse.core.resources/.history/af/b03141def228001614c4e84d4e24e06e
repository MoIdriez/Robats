/*
 * CrazyflieServer.cpp
 *
 *  Created on: 4 May 2016
 *      Author: midries
 */
#include <iostream>
#include <sstream>
#include "CrazyflieServer.h"
#include <string>
#include <cstring>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

CrazyflieServer::CrazyflieServer(int port, int* data): port(port), data(data), clientsocket(0) {
		if (port < 1024) {
			cout << "ERROR, no port provided\n" << endl;
			exit(1);
		}
		serversocket = socket(AF_INET, SOCK_STREAM, 0);
		if (serversocket < 0) {
			cout << "ERROR opening socket" << endl;
		}
		//memset(&serv_addr, 0, sizeof(serv_addr));
		serveraddress.sin_family = AF_INET;
		serveraddress.sin_addr.s_addr = INADDR_ANY;
		serveraddress.sin_port = htons(port);
		mainthread = thread(&CrazyflieServer::start, this);
		mainthread.detach();
}

void CrazyflieServer::start() {
	/* Bind the server socket */
	if (bind(serversocket, (struct sockaddr *) &serveraddress, sizeof(serveraddress)) < 0)
		cout << "ERROR on binding" << endl;
	/* Listen on the server socket */
	if (listen(serversocket, 5) < 0) {
		cout << "Failed to listen on server socket" << endl;
	}

	struct sockaddr_in cli_addr;
	/* Run until cancelled */
	for(;;) {
		socklen_t clientlen = sizeof(cli_addr);
		/* Wait for client connection */
		clientsocket = accept(serversocket, (struct sockaddr *) &cli_addr, &clientlen);
		if (clientsocket < 0) {
			cout << "Failed to accept client connection" << endl;
		}
		handleClient();
	}
}

void CrazyflieServer::handleClient() {
	char buffer[32];
	int received = -1;
	/* Receive message */
	if ((received = recv(clientsocket, buffer, 32, 0)) < 0) {
		cout << "Failed to receive initial bytes from client" << endl;
	}
	else {
		for(;;){
			stringstream convert;
			convert << data[0] << "," << data[1] << "," << data[2] << "," << data[3];// << endl;
			strcpy(buffer, convert.str().c_str());
			convert.str(string());
			if (send(clientsocket, buffer, received, 0) != received) {
				cout << "Failed to send bytes to client" << endl;

			}
		}
	}
}

CrazyflieServer::~CrazyflieServer() {
	shutdown(clientsocket, 2);
	cout << "Closing socket" << endl;
}

