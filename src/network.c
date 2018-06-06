#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/socket.h> // for socket() and etc
#include <netinet/in.h> // for htons, htonl...
#include <unistd.h> // for close()
#include <netdb.h>

#define PORT 80 // 80
#define HOSTNAME /*INADDR_LOOPBACK*/ "gray-world.net"

char message[] = "GET /etc/passwd/googletut1.txt HTTP/1.1\r\nHost:gray-world.net\r\nConnection: close\r\n\r\n"; //sprintf
char buf[512];

void diagnostic(int retval, const char *message)
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

struct sockaddr_in initSockAddr(short int family, unsigned short port,
                        unsigned long hostname, unsigned char *zero)
{
    struct sockaddr_in server_addr = { family, htons(port) };
    struct hostent *host = resolve(hostname);

    memcpy(&server_addr.sin_addr, host->h_addr_list[0], host->h_length);

    return server_addr;
}

void connectionEstabilishment(int socket, struct sockaddr *addr, unsigned int len)
{
    diagnostic(connect(socket, addr, len), "Connection refuesed!");
}

void readall(int socket, char *buff, size_t len, int flags)
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

//int main()
//{

//    int _socket = socket(AF_INET, SOCK_STREAM, 0);

//    diagnostic(_socket, "Socket doesn't open!"); // create socket
//    struct sockaddr_in addr = initSockAddr(AF_INET, PORT, HOSTNAME, NULL); // init sockaddr_in
//    connectionEstabilishment(_socket, (struct sockaddr*) &addr, sizeof(addr)); // connect

//    send(_socket, message, sizeof(message), 0);
//    readall(_socket, buf, sizeof(buf), 0);

//    close(_socket);

//    return 0;
//}
