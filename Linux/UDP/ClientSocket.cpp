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
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5555);

    cout << "Please input message or [-1] to quit" << endl;

    string buffer;
    while (strcmp(buffer.c_str(), "-1") != 0) {
        getline(cin, buffer);
        int send_ok = sendto(serverSocket, buffer.c_str(), buffer.length(), 0, (sockaddr*)&addr, sizeof(addr));
        if(send_ok == -1){
            cout << "Message sent failed!" << endl;
        }
        else{
            cout << "Message sent!" << send_ok << endl;
        }

        if (strcmp(buffer.c_str(), "-1") == 0) {
            close(serverSocket);
            cout << "Socket closed" << endl;
        }
    }
    cout<<"Socket closed"<<endl;
}
