#ifndef CAPPED_BOARD_H
#define CAPPED_BOARD_H

#include<battleship.h>

unsigned char CAPPED_BOARD[SIZE][SIZE] = {
{              00,AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,     PATROL_BOAT,              00,              00,              00},
{              00,       DESTROYER,      BATTLESHIP,      BATTLESHIP,      BATTLESHIP,      BATTLESHIP,     PATROL_BOAT,              00,              00,              00},
{              00,       DESTROYER,              00,              00,              00,              00,              00,              00,              00,              00},
{              00,       DESTROYER,              00,              00,              00,              00,              00,              00,              00,              00},
{       SUBMARINE,              00,              00,              00,              00,              00,              00,              00,              00,              00},
{       SUBMARINE,              00,              00,              00,              00,              00,              00,              00,              00,              00},
{       SUBMARINE,              00,              00,              00,              00,              00,              00,              00,              00,              00},
{              00,              00,              00,              00,              00,              00,              00,              00,              00,              00},
{              00,              00,              00,              00,              00,              00,              00,              00,              00,              00},
{              00,              00,              00,              00,              00,              00,              00,              00,              00,              00}
};

#endif
