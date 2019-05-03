#ifndef EDGE_BOARD_H
#define EDGE_BOARD_H

#include<battleship.h>

unsigned char EDGE_BOARD[SIZE][SIZE] = {
{              00,              00,              00,              00,              00,              00,              00,              00,              00,              00},
{       SUBMARINE,              00,              00,              00,              00,              00,              00,              00,              00,       DESTROYER},
{       SUBMARINE,              00,              00,              00,              00,              00,              00,              00,              00,       DESTROYER},
{       SUBMARINE,              00,      BATTLESHIP,      BATTLESHIP,      BATTLESHIP,      BATTLESHIP,              00,              00,              00,       DESTROYER},
{              00,              00,              00,              00,              00,              00,              00,              00,              00,              00},
{              00,              00,              00,              00,              00,              00,              00,              00,              00,              00},
{              00,              00,              00,              00,              00,              00,              00,              00,              00,              00},
{              00,              00,              00,              00,              00,              00,              00,              00,              00,              00},
{              00,              00,              00,              00,              00,              00,              00,              00,              00,              00},
{AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,              00,              00,              00,     PATROL_BOAT,     PATROL_BOAT}
};

#endif
