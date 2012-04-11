#include "client.h"

using namespace std;

void client(){
	string confirm;

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
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	//retype family
	addr.sin_family = AF_INET;
	//port
	addr.sin_port = htons(1234);

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
		}
	}
}