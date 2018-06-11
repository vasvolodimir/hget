#include "../include/io.h"

userData uData = { 0 };

void inputVerification(char *string)
{
    if(!string)
    {
        printf("%s\n", "Enter all parameters!\n"
               "get -h <host> -s <source> -d <destination>");

        exit(EXIT_FAILURE);
    }
}

userData parse(int argc, char **argv)
{
     int result = 0;
     const char *optstring = ":h:s:d:";

     while ( (result = getopt(argc, argv, optstring)) != INVALID_INDEX)
     {
         inputVerification(optarg);

         switch (result)
         {
             case 'h': memcpy(uData.hostname, optarg, sizeof(uData.hostname));
             break;

             case 's': memcpy(uData.source, optarg, sizeof(uData.source));
             break;

             case 'd': memcpy(uData.destination, optarg, sizeof(uData.destination));
             break;

             default:
             break;
         }
     }

     return uData;
}

void writeToFile(const char *chunk)
{
    FILE *file = fopen(uData.destination, "a");

    fprintf(file, chunk);
    fclose(file);
}

char *getSubString(const char *data, const char *delim)
{
    size_t size = strlen(data);
    char *copy = (char*) malloc(size + 1); // copy of data

    memset(copy, '\0', size + 1);
    strncpy(copy, data, size);

    char *string = strtok(copy, delim);
    char *sub;

    while(string)
    {
        sub = string;
        string = strtok (NULL, delim);
    }

    size = strlen(sub);
    char *result = (char*) malloc(size + 1); // workaround to avoid memory leak
    *(result + size + 1) = '\0';
    strncpy(result, sub, size);

    free(copy);

    return result;
}

char *findEndOfHeader(const char *buffer)
{
    const char *end = "\r\n\r\n";
    size_t space_size = sizeof(end);

    char *result = strstr(buffer, end);

    return result ? strstr(buffer, end) + space_size : NULL;
}
