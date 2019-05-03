#ifndef SHOOTER_H
#define SHOOTER_H

#include<battleship.h>

typedef struct shooter Shooter;

Shooter* newShooter(void);
void clearShooter(Shooter*);
Shot nextShot(Shooter*);
void registerResult(Shooter*, int);

#endif
