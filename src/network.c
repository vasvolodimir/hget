#include "../include/network.h"

char chunkBuffer[BUFFER_SIZE] = { 0 };

void networkStatus(int retval, const char *message)
{
    if(retval < 0)
    {
        perror(message);
        exit(retval);
    }
}

struct hostent *resolve(const char *hostname)
{
    struct hostnet *hn;

    if(!(hn = gethostbyname(hostname)))
    {
        perror("Hostname doesn't resolve!");
        exit(EXIT_FAILURE);
    }

    return hn;
}

struct sockaddr_in initServerData(short int family, unsigned short port,
                                  unsigned long hostname, unsigned char *zero)
{
    struct sockaddr_in serverData = { family, htons(port) };
    struct hostent *host = resolve(hostname);

    memcpy(&serverData.sin_addr, host->h_addr_list[0], host->h_length);

    return serverData;
}

void createConnection(int socket, struct sockaddr *addr, unsigned int len)
{
    networkStatus(connect(socket, addr, len), "Connection refused!");
}

void readFromHost(int socket, char *buff, size_t len, int flags)
{
    int size = 0;

    while(1)
    {
        memset(buff, 0, len);
        size = recv(socket, buff, len, flags);
        if(size <= 0) break;
        else printf("%s", buff);
    }
}

int createSocket()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    networkStatus(sock, "Socket doesn't open!");

    return sock;
}

int connectToHost(userData data)
{
    int sock = createSocket();
    struct sockaddr_in serverData = initServerData(AF_INET, PORT, data.hostname, NULL);

    createConnection(sock, (struct sockaddr*) &serverData, sizeof(serverData));

    return sock;
}

void sendToHost(int socket)
{
    char *message = createMessage();
    send(socket, message, strlen(message), 0);
}

char *createMessage()
{
    sprintf(chunkBuffer, "GET %s HTTP/1.1\r\nHost:%s\r\nConnection: close\r\n\r\n", uData.source, uData.hostname);
    return chunkBuffer;
}
