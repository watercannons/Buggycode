#ifndef PLACER_H
#define PLACER_H

#include<battleship.h>

typedef struct placer Placer;

Placer* newPlacer(void);
void clearPlacer(Placer*);
void placeBoats(Placer*, int);
void registerShot(Placer*, Shot);

#endif
