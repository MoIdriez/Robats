#ifndef COMMUNICATIONENGINE_CRAZYSERVER_H_
#define COMMUNICATIONENGINE_CRAZYSERVER_H_

#include <thread>
#include <netinet/in.h>

using namespace std;

class CrazyServer {
public:
	CrazyServer(int port, int* data);
	virtual ~CrazyServer();

private:
	int* data; // [isNew, Sonar, AccX, AccY, AccZ, GyrX, GyrY, GyrZ]
	int port;
	int serversocket;
	int clientsocket;
	thread mainthread;
	struct sockaddr_in serveraddress;

	void start();
	void handleClient();
};

#endif /* COMMUNICATIONENGINE_CRAZYFLIESERVER_H_ */
