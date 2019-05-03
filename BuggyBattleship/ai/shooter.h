#ifndef SHOOTER_H
#define SHOOTER_H

#include<battleship.h>
#include "linkedList.h"

typedef struct Shooter Shooter;

Shooter* newShooter(void);

Shot* nextShot(Shooter* s);

void processResult(Shooter* shooter, int result);

void clearShooter(Shooter* shooter);

void deleteShooter(Shooter* shooter);

#endif
