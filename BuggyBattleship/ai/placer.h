#ifndef PLACER_H
#define PLACER_H

#include<battleship.h>

typedef struct Placer Placer;

Placer* newPlacer(void);

void makeBoard(Placer* p, unsigned char board[SIZE][SIZE]);

void printBoard(unsigned char board[SIZE][SIZE]);

void processShot(Placer* p, Shot s);

void clearPlacer(Placer* p);

void deletePlacer(Placer* placer);

#endif
