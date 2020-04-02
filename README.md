# SocketProgramming
Basic server - client methods for both Windows and Linux
## WorkFlow
- ***Server*** 
1. Create a socket
2. Bind the socket
3. Listen on the socket
4. Accept a connection
5. Send and receive data
6. Disconnect
- ***Client*** 
1. Create a socket
2. Connect to the server
3. Send and receive data
4. Disconnect
## Difference between Windows and Linux for this project
- Need to link winsock library file named WS2_32.lib in Windows environment
- Few functions i.e. closesocket(Windows) vs. close(Linux)
- Error Reporting
