/**************************************************************/
/* Cory Wolfe
/* server.cpp
/* CREDIT:
/* http://www.youtube.com/watch?v=jBAAbp6cNpg&feature=channel
/**************************************************************/

//For testing concerns, you may need to activate telnet. To do so
//Go to Control Panel -> Programs -> Programs and Features
// -> choose Turn windows features on and off -> check telnet server/client
// -> click OK

//open cmd, type "telnet"
//format to start: "open [ip] [port]"
//->Connecting To [ip]... , should appear.

#include "server.h"

using namespace std;

class my_net{

public:

void server(string my_ip, int my_port){

	//start Winsock DLL
	long answer;
	WSAData wsaData;
	WORD DLLVERSION;
	DLLVERSION = MAKEWORD(2,1);
	//start the DLL with WSAStartup
	answer = WSAStartup(DLLVERSION, &wsaData);

	//DLL was started, can use Winsock functions
	SOCKADDR_IN addr;
	//addr is our structure
	int addrlen = sizeof(addr);

	//create sockets
	//sListen = socket listening for incoming connection
	SOCKET sListen;
	//sConnect = socket which is operating if a connection is found
	SOCKET sConnect;

	//setup our sockets.
	sConnect = socket(AF_INET, SOCK_STREAM, NULL);

	//structure set up. inet_addr = IP of program
	addr.sin_addr.s_addr = inet_addr(my_ip.c_str());
	//retype family
	addr.sin_family = AF_INET;
	//setup port
	//IP: 127.0.0.1   PORT: 1234
	addr.sin_port = htons(my_port);

	//now we have to setup our sListen-socket
	sListen = socket(AF_INET, SOCK_STREAM, NULL);
	//bind socket; same ip and port, socket becomes the strucutre "addr"
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	//now we have to listen for incoming connection
	listen(sListen, SOMAXCONN);
	//SOMAXCONN means the saerver listening without limit

	//what to do if connection found
	for(;;){
		cout << "Waiting for an incoming connection" << endl;
		
		if(sConnect = accept(sListen, (SOCKADDR*)&addr, &addrlen)){
			cout << "A connection was found" << endl;
			//send message
			//answer = send([socket], ["message"], [numberof chars in message+1], NULL);
			answer = send(sConnect, "Testing...", 11, NULL);
		}

	}
}

void client(string my_ip, int my_port){
	string confirm;
	//receive the message from server
	char message[200];
	string strmessage;

	//Winsock-DLL
	long answer;
	WSAData wsaData;
	WORD DLLVersion;
	DLLVersion = MAKEWORD(2,1);
	answer = WSAStartup(DLLVersion, &wsaData);
	//same as in server

	//setup our sockets and the SOCKADDR_IN
	SOCKADDR_IN addr;
	int addrlen = sizeof(addr);

	//setup socket
	SOCKET sConnect;
	sConnect = socket(AF_INET, SOCK_STREAM, NULL);

	//Here, type IP of server (127.0.0.1)
	addr.sin_addr.s_addr = inet_addr(my_ip.c_str());
	//retype family
	addr.sin_family = AF_INET;
	//port
	addr.sin_port = htons(my_port);

	//ask user of client if he wants to connect to server
	cout << "Do you want to connect to your server? [Y,N]" << endl;
	cin >> confirm;
	//if no, client closes.
	if(confirm == "N"){
		exit(1);
	}else{
		//else the client will connect to server
		//sConnect = socket, "addr" = structure
		if(confirm == "Y"){
			connect(sConnect, (SOCKADDR*)&addr, sizeof(addr));
			//receive the message from server
			// recv([socket], [message storage], sizeof char, NULL);
			answer = recv(sConnect, message, sizeof(message), NULL);

			strmessage = message;
			cout << strmessage << endl;

			getchar();
			//test
		}
	}
	//getchar();
}

};
