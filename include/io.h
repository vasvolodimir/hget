#ifndef IO_H
#define IO_H

#define INVALID_INDEX -1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/shared.h"

void parse(int argc, char **argv);
void inputVerification(char *string);

#endif // IO_H
