#ifndef GAME_H
#define GAME_H

#include<battleship.h>

typedef struct
{
   int pipes[2];
   int pid;
   char* name;
   char board[SIZE][SIZE];
   unsigned short shots;
   unsigned short misses;
   unsigned short hit;
   unsigned short sunk;
   unsigned short boats[NUMBER_OF_SHIPS];
   unsigned int win;
   unsigned int loss;
   unsigned int tie;
} Player;

void playGame(Player p[2], int d, int i);

void closeChild(Player p);

#endif
