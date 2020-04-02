#include <iostream>
#include <winsock2.h>

using namespace std;

int main()
{
    WSADATA  WSAData;
    SOCKET serverSocket, clientSocket;
    SOCKADDR_IN serverAddr, clientAddr;

    int clientLength = sizeof(serverAddr);

    WSAStartup(MAKEWORD(2, 0), &WSAData);
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5555);

    bind(serverSocket, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 0);

    cout << "Listening for incoming connections" << endl;

    char buffer[1024];
    int clientAddrSize = sizeof(clientAddr);
   //UDP don not neet to accept
        cout << "Client connected!" << endl;
        while (strcmp(buffer, "-1") != 0) {
            memset(buffer, 0, sizeof(buffer));
            //UDP apply recvfrom function
            int bytesIn = recvfrom(serverSocket, buffer, sizeof(buffer), 0, (sockaddr*)&serverAddr, &clientLength);
            if (bytesIn == SOCKET_ERROR) {
                cout << "Error receiving from client " << WSAGetLastError() << endl;
                continue;
            }
            cout << "Client says: " << buffer << endl;
        }
        if (strcmp(buffer, "-1") == 0) {
            closesocket(serverSocket);
            std::cout << "Socket closed" << endl;
        }


    system("pause");
}

