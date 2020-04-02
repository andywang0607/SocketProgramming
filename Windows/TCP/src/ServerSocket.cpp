// ServerSocket.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//


#include <iostream>
#include <winsock2.h>

using namespace std;

int main()
{
    WSADATA  WSAData;
    SOCKET serverSocket, clientSocket;
    SOCKADDR_IN serverAddr, clientAddr;

    WSAStartup(MAKEWORD(2, 0), &WSAData);
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5555);

    bind(serverSocket, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 0);

    cout << "Listening for incoming connections" << endl;

    char buffer[1024];
    int clientAddrSize = sizeof(clientAddr);

    if ((clientSocket = accept(serverSocket, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET) {
        cout << "Client connected!" << endl;
        while (strcmp(buffer, "-1") != 0) {
            memset(buffer, 0, sizeof(buffer));
            recv(clientSocket, buffer, sizeof(buffer), 0);
            cout << "Client says: " << buffer << endl;
        }
        if (strcmp(buffer, "-1") == 0) {
            closesocket(clientSocket);
            std::cout << "Socket closed" << endl;
        }
    }

    system("pause");
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的秘訣:
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
