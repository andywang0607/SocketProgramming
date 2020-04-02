# SocketProgramming
Basic server - client methods for both Windows and Linux
## Description
Implement communication between two processes with socket, applying TCP and UDP
![Execute](source/result.png)
## WorkFlow
- **TCP Server** 
1. Create a socket
2. Bind the socket
3. Listen on the socket
4. Accept a connection
5. Send and receive data
6. Disconnect
- **TCP Client** 
1. Create a socket
2. Connect to the server
3. Send and receive data
4. Disconnect

- **UDP Server** 
1. Create a socket
2. Bind the socket
3. Listen on the socket
4. Send and receive data
5. Disconnect
- **UDP Client** 
1. Create a socket
2. Send and receive data
3. Disconnect

## Difference between Windows and Linux for this project
- Need to link winsock library file named WS2_32.lib in Windows environment
- Few functions i.e. closesocket(Windows) vs. close(Linux)
- Error Reporting
