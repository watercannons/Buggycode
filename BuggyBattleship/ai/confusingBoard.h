#ifndef CONFUSING_BOARD_H
#define CONFUSING_BOARD_H

#include<battleship.h>

unsigned char CONFUSING_BOARD[SIZE][SIZE] = {
{              00,              00,              00,     PATROL_BOAT,              00,              00,              00,              00,              00,               00},
{              00,              00,              00,     PATROL_BOAT,              00,              00,              00,              00,              00,               00},
{       SUBMARINE,       SUBMARINE,       SUBMARINE,              00,              00,              00,              00,              00,              00,               00},
{              00,              00,      BATTLESHIP,      BATTLESHIP,      BATTLESHIP,      BATTLESHIP,       DESTROYER,       DESTROYER,       DESTROYER,               00},
{              00,              00,              00,              00,              00,              00,              00,              00,              00,               00},
{              00,              00,              00,              00,AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,               00},
{              00,              00,              00,              00,              00,              00,              00,              00,              00,               00},
{              00,              00,              00,              00,              00,              00,              00,              00,              00,               00},
{              00,              00,              00,              00,              00,              00,              00,              00,              00,               00},
{              00,              00,              00,              00,              00,              00,              00,              00,              00,               00}
};

#endif
