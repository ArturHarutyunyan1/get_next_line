#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

char *get_next_line(int fd);

#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024

#endif