#ifndef NETWORK_H
#define NETWORK_H

#include <sys/socket.h> // for socket() and etc
#include <netinet/in.h> // for htons, htonl...
#include <unistd.h> // for close()
#include <netdb.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/shared.h"
#include "../include/io.h"

#define PORT 80

void networkStatus(int retval, const char *message);

struct hostent *resolve(const char *hostname);
struct sockaddr_in initServerData(short int family, unsigned short port,
                                  char *hostname, unsigned char *zero);
int createSocket();
void createConnection(int socket, struct sockaddr *addr, unsigned int len);
char *createMessage();
int fileExist(const char *buffer);

void sendToHost(int socket);
void readFromHost(int socket, char *buff, size_t len, int flags);
int connectToHost(userData data);

#endif
