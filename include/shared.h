#ifndef SHARED_H
#define SHARED_H

#define INVALID_INDEX -1
#define BUFFER_SIZE 512

//XXX: move to .c file
//XXX: no static allocation
typedef struct
{
   char hostname[50];
   char source[50];
   char destination[50];

} userData;

extern userData uData;
extern char chunkBuffer[BUFFER_SIZE];

#endif
