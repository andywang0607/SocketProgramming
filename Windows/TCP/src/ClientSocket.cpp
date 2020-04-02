#include <iostream>
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <string>
using namespace std;

int main()
{
    WSADATA  WSAData;
    SOCKET serverSocket;
    SOCKADDR_IN addr;

    WSAStartup(MAKEWORD(2, 0), &WSAData);
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    PCSTR src = TEXT("127.0.0.1");
    InetPton(AF_INET, src, &addr.sin_addr.s_addr);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(5555);

    connect(serverSocket, (SOCKADDR *)& addr, sizeof(addr));
	
    cout << "Connected to server" << endl;
    cout << "please input message or [-1] to quit" << endl;


    string buffer;
    while (strcmp(buffer.c_str(), "-1") != 0) {
        getline(cin, buffer);
        send(serverSocket, buffer.c_str(), buffer.length(), 0);
        cout << "Message sent!" << endl;

        if (strcmp(buffer.c_str(), "-1") == 0) {
            closesocket(serverSocket);
            WSACleanup();
            cout << "Socket closed" << endl;
        }
    }
    system("pause");
}
