#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <arpa/inet.h>


using namespace std;

int main()
{
    int serverSocket = 0;

    struct sockaddr_in addr;
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5555);

    connect(serverSocket, (struct sockaddr *)&addr, sizeof(addr));
    cout<<"Connected to server!"<<endl;
    string buffer;
    while (strcmp(buffer.c_str(), "-1") != 0) {
        getline(cin, buffer);
        send(serverSocket, buffer.c_str(), buffer.length(), 0);
        cout << "Message sent!" << endl;

        if (strcmp(buffer.c_str(), "-1") == 0) {
            close(serverSocket);
            cout << "Socket closed" << endl;
        }
    }
    cout<<"Socket closed"<<endl;
}
