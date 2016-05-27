//============================================================================
// Name        : Test.cpp
// Author      : Mohamed Idries
// Version     :
// Copyright   : Just use it for awesome stuff
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>       // std::cout, std::endl
#include <thread>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <sstream>
#include <string>
#include <cstring>
using namespace std;


class awesome {
public:
	awesome(int* data, int size) : data(data), size(size) {
		thread mainthread (&awesome::startserver, this);
		mainthread.detach();
	}

	bool equal(int* x, int* y) {
		for (int i = 0; i < size; i++){
			if (x[i] != y[i]){
				return false;
			}
		}
		return true;

	}

	void startserver() {
		int port = 8888;
		int serversocket = socket(AF_INET, SOCK_STREAM, 0);
		if (serversocket < 0) {
			cout << "ERROR opening socket" << endl;
		}
		//memset(&serv_addr, 0, sizeof(serv_addr));
		serveraddress.sin_family = AF_INET;
		serveraddress.sin_addr.s_addr = INADDR_ANY;
		serveraddress.sin_port = htons(port);

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
			int clientsocket = accept(serversocket, (struct sockaddr *) &cli_addr, &clientlen);
			if (clientsocket < 0) {
				cout << "Failed to accept client connection" << endl;
			}
			char buffer[64];
			int received = -1;
			/* Receive message */
			if ((received = recv(clientsocket, buffer, 32, 0)) < 0) {
				cout << "Failed to receive initial bytes from client" << endl;
			}
			else {
				int temp[4] = { data[0], data[1], data[2], data[3] };
				for(;;){
					if (!equal(temp, data)) {
						stringstream convert;
						convert << temp[0] << "," << temp[1] << "," << temp[2] << "," << temp[3];// << endl;
						strcpy(buffer, convert.str().c_str());
						convert.str(string());
						if (send(clientsocket, buffer, received, 0) != received) {
							cout << "Failed to send bytes to client" << endl;

						}
						for (int j = 0; j < size; j++) {
							temp[j] = data[j];
						}
					}

				}
			}
		}
	}
private:
	int size;
	int* data;
	struct sockaddr_in serveraddress;
};


//int main() {
//	int x [4] =  { 10, 10, 10, 10 };
//	new awesome(x, 4);
//	for (int i=25; i>0; --i) {
//		for (int j = 0; j < 4; j++) {
//			x[j] = i;
//		}
//		cout << "Send: "<< x[0] << "||" << x[1] << "||"  << x[2] << "||" << x[3] << endl;
//	    sleep(1);
//	  }
//}
