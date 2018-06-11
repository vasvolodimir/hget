#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/shared.h"

//XXX: rename with "_" instead on capital
userData parse(int argc, char **argv);
void input_verification(char *string);
void write_to_file(const char *chunk);

char *getSubString(const char *data, const char *delim);
char *findEndOfHeader(const char *buffer);

#endif // IO_H
