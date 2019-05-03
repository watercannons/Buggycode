#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "placer.h"
#include <battleship.h>
#include "stackedSidesBoard.h"
#include "confusingBoard.h"
#include "cappedBoard.h"

#define HORIZONTAL 0
#define VERTICAL 1

struct Placer
{
   unsigned char game;
   unsigned char turn;
   unsigned char board[SIZE][SIZE];
   unsigned short history[SIZE][SIZE];
   Shot lastShot;
   unsigned char hitCount;
   unsigned char badShotCount;
   unsigned char i;
};

typedef struct
{
   unsigned char x;
   unsigned char y;
   unsigned char orientation;
   unsigned char length;
} Placement;

Placer* newPlacer()
{
   Placer* res = calloc(1, sizeof(Placer));
   clearPlacer(res);
   res->game = 0;
   return res;
}

int checkPos(unsigned char board[SIZE][SIZE], Placement p)
{
   int i;
   if (p.orientation)
   {
      for (i = 0; i < p.length; i++)
      {
         if (board[p.x][p.y + i] != OPEN_WATER)
         {
            return 0;
         }
      }
   }
   else
   {
      for (i = 0; i < p.length; i++)
      {
         if (board[p.x + i][p.y] != OPEN_WATER)
         {
            return 0;
         }
      }
   }
   return 1;
}

Placement randomPlacement(unsigned char board[SIZE][SIZE], int size)
{
   Placement pl;
   pl.length = size;
   do
   {
      pl.orientation = rand() % 2? HORIZONTAL:VERTICAL;
      pl.x = rand() % (SIZE - (!pl.orientation? size:1));
      pl.y = rand() % (SIZE - (pl.orientation? size:1));
   } while (!checkPos(board, pl));
   return pl;
}

void placeBoat(unsigned char board[SIZE][SIZE], Placement pl, int num)
{
   int i;
   if (pl.orientation)
   {
      for (i = 0; i < pl.length; i++)
      {
         board[pl.x][pl.y + i] = num;
      }
   }
   else 
   {
      for (i = 0; i < pl.length; i++)
      {
         board[pl.x + i][pl.y] = num;
      }
   }
}

void placeRandom(unsigned char board[SIZE][SIZE])
{
   placeBoat(board, randomPlacement(board, SIZE_PATROL_BOAT), PATROL_BOAT);
   placeBoat(board, randomPlacement(board, SIZE_SUBMARINE), SUBMARINE);
   placeBoat(board, randomPlacement(board, SIZE_DESTROYER), DESTROYER);
   placeBoat(board, randomPlacement(board, SIZE_BATTLESHIP), BATTLESHIP);
   placeBoat(board, randomPlacement(board, SIZE_AIRCRAFT_CARRIER),
      AIRCRAFT_CARRIER);
}

unsigned int findRate(Placer* p, Placement pl)
{
   unsigned int i, res = 0;
   if (pl.orientation == HORIZONTAL)
   {
      for (i = 0; i < pl.length; i++)
      {
         res += p->history[pl.x + i][pl.y];
      }
   }
   else
   {
      for (i = 0; i < pl.length; i++)
      {
         res += p->history[pl.x][pl.y + i];
      }
   }
   return res;
}

Placement lowestFindRate(Placer* p, unsigned char board[SIZE][SIZE], int size)
{
   Placement res, iter;
   unsigned int min = UINT_MAX, cur;
   iter.length = size;
   for (iter.x = 0; iter.x < SIZE; ++iter.x)
   {
      for (iter.y = 0; iter.y < SIZE; ++iter.y)
      {
         iter.orientation = HORIZONTAL;
         if (iter.x + size <= SIZE && (cur = findRate(p, iter)) <= min
            && checkPos(board, iter))
         {
            min = cur;
            res = iter;
         }
         iter.orientation = VERTICAL;
         if (iter.y + size <= SIZE && (cur = findRate(p, iter)) <= min
            && checkPos(board, iter))
         {
            min = cur;
            res = iter;
         }
      }
   }
   return res;
}

void placeHidden(Placer* p, unsigned char board[SIZE][SIZE])
{
   placeBoat(board, lowestFindRate(p, board, SIZE_PATROL_BOAT), PATROL_BOAT);
   placeBoat(board, lowestFindRate(p, board, SIZE_SUBMARINE), SUBMARINE);
   placeBoat(board, lowestFindRate(p, board, SIZE_DESTROYER), DESTROYER);
   placeBoat(board, lowestFindRate(p, board, SIZE_BATTLESHIP), BATTLESHIP);
   placeBoat(board, lowestFindRate(p, board, SIZE_AIRCRAFT_CARRIER),
      AIRCRAFT_CARRIER);
}

void makeBoard(Placer* p, unsigned char board[SIZE][SIZE])
{
   Shot s;
   if (p->game == 1)
   {
      memcpy(board, STACKED_SIDES_BOARD, SIZE*SIZE);
      memcpy(p->board, board, SIZE*SIZE);
   }
   else if (p->hitCount > 11 && (p->badShotCount < 10 || p->hitCount < 19))
   {
      p->i++;
      if (p->i == 1)
      {
         memcpy(board, CONFUSING_BOARD, SIZE*SIZE);
      }
      else if (p->i == 2)
      {
         memcpy(board, CAPPED_BOARD, SIZE*SIZE);
      }
      else
      {
         memset(board, OPEN_WATER, SIZE*SIZE);
         placeHidden(p, board);
      }
      memcpy(p->board, board, SIZE*SIZE);
   }
   else
   {
      memcpy(board, p->board, SIZE*SIZE);
   }
   p->badShotCount = p->hitCount = 0;
   for (s.row = 0; s.row < SIZE; ++s.row)
   {
      for (s.col = 0; s.col < SIZE; ++s.col)
      {
         p->history[s.row][s.col] >>= 3;
      }
   }
}

void processShot(Placer* p, Shot s)
{
   if (s.row < SIZE && s.col < SIZE &&
      (p->lastShot.row != s.row || p->lastShot.col != s.col))
   {
      if (p->history[s.row][s.col] + p->turn*p->turn*p->turn > USHRT_MAX)
      {
         p->history[s.row][s.col] = USHRT_MAX;
      }
      else
      {
         p->history[s.row][s.col] += p->turn*p->turn*p->turn;
      }
      if (p->board[s.row][s.col] != OPEN_WATER)
      {
         p->hitCount++;
      }
      p->lastShot = s;
   }
   else
   {
      p->badShotCount++;
   }
   p->turn--;
}

void clearPlacer(Placer* p)
{
   p->game++;
   p->turn = MAX_SHOTS;
   p->lastShot.row = p->lastShot.col = USHRT_MAX;
}

void deletePlacer(Placer* p)
{
   free(p);
}
