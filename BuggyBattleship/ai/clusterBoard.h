#ifndef CLUSTERED_BOARD_H
#define CLUSTERED_BOARD_H

#include<battleship.h>

unsigned char CLUSTERED_BOARD[SIZE][SIZE] = {
{              00,              00,              00,              00,              00,              00,              00,              00,              00,              00},
{              00,              00,              00,              00,              00,              00,              00,       DESTROYER,       SUBMARINE,              00},
{              00,              00,              00,              00,              00,              00,              00,       DESTROYER,       SUBMARINE,              00},
{              00,              00,              00,              00,              00,              00,              00,       DESTROYER,       SUBMARINE,              00},
{              00,              00,              00,              00,              00,              00,              00,              00,              00,              00},
{              00,              00,              00,              00,              00,              00,              00,              00,              00,              00},
{              00,              00,      BATTLESHIP,      BATTLESHIP,      BATTLESHIP,      BATTLESHIP,              00,     PATROL_BOAT,     PATROL_BOAT,              00},
{              00,AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,              00,              00,              00,              00},
{              00,              00,              00,              00,              00,              00,              00,              00,              00,              00},
{              00,              00,              00,              00,              00,              00,              00,              00,              00,              00}
};

#endif
