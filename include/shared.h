#ifndef SHARED_H
#define SHARED_H

typedef struct
{
   char hostname[50];
   char source[50];
   char destination[50];

} userData;

extern userData uData;

#endif
