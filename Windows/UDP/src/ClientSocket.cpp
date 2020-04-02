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
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

    PCSTR src = TEXT("127.0.0.1");
    InetPton(AF_INET, src, &addr.sin_addr.s_addr);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(5555);
    /* UDP do not need to connect */

    std::cout << "please input message or [-1] to quit" << endl;


    string buffer;
    while (strcmp(buffer.c_str(), "-1") != 0) {
        getline(cin, buffer);
        // UDP apply sendto function
        int sendOk = sendto(serverSocket, buffer.c_str(), buffer.length(), 0, (sockaddr*)&addr, sizeof(addr));
        if (sendOk == SOCKET_ERROR)
        {
            cout << "That didn't work! " << WSAGetLastError() << endl;
        }
        else {
            std::cout << "Message sent!" << endl;
        }
        if (strcmp(buffer.c_str(), "-1") == 0) {
            closesocket(serverSocket);
            WSACleanup();
            std::cout << "Socket closed" << endl;
        }
    }
    system("pause");
}
