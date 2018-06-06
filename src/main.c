#include "../include/io.h"
#include "../include/network.h"

int main(int argc, char *argv[])
{
    int host = connectToHost(parse(argc, argv)); // socket descriptor

    sendToHost(host);
    readFromHost(host, chunkBuffer, sizeof(chunkBuffer), 0);
    close(host);

    return 0;
}
