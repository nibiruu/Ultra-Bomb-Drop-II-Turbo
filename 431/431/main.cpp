#include "server.cpp"

using namespace std;

int main(){
	cout << "Server:  1" << endl;
	cout << "Client:  2" << endl;
	int op1=0;
	my_net connect1;
	scanf("%d", &op1);
	if(op1==1){
		string my_ip;
		int my_port;
		cout << "IP:  ";
		cin >> my_ip;
		cout << "\nPort:  ";
		cin >> my_port;
		connect1.server(my_ip, my_port);
	}
	else if(op1==2){
		string my_ip;
		int my_port;
		cout << "IP to connect to:  ";
		cin >> my_ip;
		cout << "\nPort to connect to:  ";
		cin >> my_port;

		connect1.client(my_ip, my_port);
	}
	else
		cout << "Option failed" << endl;
}