#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <sys/types.h>

using namespace std;

int main()
{
        int server = 0, client = 0; // Linux specific
        struct sockaddr_in serverAddr; //Linux specific

        server = socket(AF_INET, SOCK_STREAM, 0);

        serverAddr.sin_addr.s_addr = INADDR_ANY;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(5555);

        bind(server, (struct sockaddr*)& serverAddr, sizeof(serverAddr));
        listen(server, 0 );

        cout<<"Listening for incoming connections..."<<endl;
        char buffer[1024];

        client = accept(server,(struct sockaddr*)NULL,NULL);
        cout<<"Client connected!"<<endl;
        while (strcmp(buffer, "-1") != 0) {
            memset(buffer, 0, sizeof(buffer));
            recv(client, buffer, sizeof(buffer), 0);
            cout << "Client says: " << buffer << endl;
        }
        if (strcmp(buffer, "-1") == 0) {
            close(client);
            std::cout << "Socket closed" << endl;
        }
        cout<<"Client disconnected"<<endl;
}
