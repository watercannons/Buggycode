#ifndef STACKED_SIDES_BOARD_H
#define STACKED_SIDES_BOARD_H

#include "battleship.h"

unsigned char STACKED_SIDES_BOARD[SIZE][SIZE] = {
   {              00,              00,              00,              00,              00,              00,              00,              00,              00,              00},
   {              00,              00,              00,              00,              00,              00,              00,              00,       SUBMARINE,       DESTROYER},
   {              00,              00,              00,              00,              00,              00,              00,              00,       SUBMARINE,       DESTROYER},
   {              00,              00,              00,              00,              00,              00,              00,              00,       SUBMARINE,       DESTROYER},
   {              00,              00,              00,              00,              00,              00,              00,              00,              00,              00},
   {              00,              00,              00,              00,              00,              00,              00,              00,              00,              00},
   {              00,              00,              00,              00,              00,              00,              00,              00,              00,              00},
   {              00,              00,              00,              00,              00,              00,              00,              00,              00,              00},
   {              00,      BATTLESHIP,      BATTLESHIP,      BATTLESHIP,      BATTLESHIP,              00,              00,     PATROL_BOAT,     PATROL_BOAT,              00},
   {AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,AIRCRAFT_CARRIER,              00,              00,              00,              00,              00}
};

#endif
