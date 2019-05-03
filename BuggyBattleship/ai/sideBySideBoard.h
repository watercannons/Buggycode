#ifndef SIDE_BY_SIDE_BOARD_H
#define SIDE_BY_SIDE_BOARD_H

#include<battleship.h>

unsigned char SIDE_BY_SIDE_BOARD[SIZE][SIZE] = { 
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 55, 55, 0, 0, 11, 0},
   {0, 0, 0, 33, 33, 33, 22, 0, 11, 0},
   {0, 0, 0, 0, 0, 0, 22, 0, 11, 0},
   {0, 0, 0, 0, 0, 0, 22, 0, 11, 0},
   {0, 0, 0, 0, 0, 0, 22, 0, 11, 0},
   {0, 0, 0, 0, 0, 44, 44, 44, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

#endif