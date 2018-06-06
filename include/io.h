#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/shared.h"

userData parse(int argc, char **argv);
void inputVerification(char *string);

#endif // IO_H
