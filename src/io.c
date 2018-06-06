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
