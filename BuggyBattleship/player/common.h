#ifndef COMMON_H
#define COMMON_H

#include<battleship.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_BROWN   "\033[22;33m"
#define ANSI_COLOR_WHITE   "\033[01;37m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void clearline(void);

void printBoard(unsigned char[SIZE][SIZE], char* (*)(char));

void getCoordinate(Shot* p, int col, int row);

#endif
