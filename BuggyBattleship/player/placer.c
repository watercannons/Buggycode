#include<battleship.h>
#include "placer.h"
#include "common.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#ifdef REPLAY
#include <replay.h>
#include <replay_undef.h>
#include <fd_replay.h>
#endif /* REPLAY */


struct placer {
  unsigned char board[SIZE][SIZE];
  unsigned short boats[NUMBER_OF_SHIPS];
};

Placer* newPlacer()
{
  Placer* p = malloc(sizeof(Placer));
  if (!p)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  return p;
}

void clearPlacer(Placer* p)
{
  memset(p->board, OPEN_WATER, SIZE*SIZE);
  memset(p->boats, 0, NUMBER_OF_SHIPS);
}

static char readChar(char* msg, char* err, char* options)
{
  char c;
  int i = 0, tmp;
  do
  {
    printf("%s", msg);
    tmp = scanf(" %c", &c);
    if (tmp == EOF)
      {
        fprintf(stderr, "Unexpected EOF.");
        exit(EXIT_FAILURE);
      }
    else if (!tmp)
      {
        printf("%s", err);
        continue;
      }
    while (options[i])
      {
        if (c == options[i++])
          return c;
      }
    i = 0;
    printf("%s", err);
    clearline();
  } while (1);
}

#define SHOT(BOAT) ~((char) (BOAT))

static char* idToHuman(char c)
{
  switch (c)
    {
    case OPEN_WATER:
      return ANSI_COLOR_BLUE "w" ANSI_COLOR_RESET;
    case SHOT(OPEN_WATER):
      return ANSI_COLOR_WHITE "o" ANSI_COLOR_RESET;
    case PATROL_BOAT:
      return ANSI_COLOR_YELLOW "P" ANSI_COLOR_RESET;
    case SHOT(PATROL_BOAT):
      return ANSI_COLOR_RED "p" ANSI_COLOR_RESET;
    case SUBMARINE:
      return ANSI_COLOR_GREEN "S" ANSI_COLOR_RESET;
    case SHOT(SUBMARINE):
      return ANSI_COLOR_RED "s" ANSI_COLOR_RESET;
    case DESTROYER:
      return ANSI_COLOR_MAGENTA "D" ANSI_COLOR_RESET;
    case SHOT(DESTROYER):
      return ANSI_COLOR_RED "d" ANSI_COLOR_RESET;
    case BATTLESHIP:
      return ANSI_COLOR_BROWN "B" ANSI_COLOR_RESET;
    case SHOT(BATTLESHIP):
      return ANSI_COLOR_RED "b" ANSI_COLOR_RESET;
    case AIRCRAFT_CARRIER:
      return ANSI_COLOR_CYAN "A" ANSI_COLOR_RESET;
    case SHOT(AIRCRAFT_CARRIER):
      return ANSI_COLOR_RED "a" ANSI_COLOR_RESET;
    default:
      return "?";
    }
}

#define HORIZONTAL 0
#define VERTICAL 1

typedef struct
{
  Shot s;
  unsigned char orientation;
  unsigned char length;
} Placement;

static int checkPos(Placer* placer, Placement p)
{
   int i;
   if (p.orientation == HORIZONTAL)
   {
      for (i = 0; i < p.length; i++)
      {
         if (placer->board[p.s.row][p.s.col + i] != OPEN_WATER)
         {
            return 0;
         }
      }
   }
   else
   {
      for (i = 0; i < p.length; i++)
      {
         if (placer->board[p.s.row + i][p.s.col] != OPEN_WATER)
         {
            return 0;
         }
      }
   }
   return 1;
}

static void placeBoat(Placer* placer, Placement pl, int num)
{
   int i;
   if (pl.orientation)
   {
      for (i = 0; i < pl.length; i++)
      {
         placer->board[pl.s.row + i][pl.s.col] = num;
      }
   }
   else 
   {
      for (i = 0; i < pl.length; i++)
      {
         placer->board[pl.s.row][pl.s.col + i] = num;
      }
   }
}

static void placeShip(char* ship, int length, int num, Placer* placer)
{
   Placement p;
   char tmp;
   printf("Enter location for %s.\n", ship);
   p.length = length;
   do
     {
       tmp = readChar("Orientation [H/V]: ",
                      "Type V for vertical or H for horizontal.\n",
                      "hHvV");
       if (tmp == 'V' || tmp == 'v')
         {
           p.orientation = VERTICAL;
           getCoordinate(&p.s, SIZE - 1, SIZE - length);
         }
       else if (tmp == 'H' || tmp == 'h')
         {
           p.orientation = HORIZONTAL;
           getCoordinate(&p.s, SIZE - length, SIZE - 1);
         }
       if (!checkPos(placer, p))
         {
           printf("Invalid placement.\n");
           printBoard(placer->board, idToHuman);
           tmp = '\0';
         }
     } while (!tmp);
   placeBoat(placer, p, num);
}

void placeBoats(Placer* placer, int wfd)
{
  char tmp;
  do {
    printBoard(placer->board, idToHuman);
    placeShip("Patrol Boat", SIZE_PATROL_BOAT, PATROL_BOAT, placer);
    printBoard(placer->board, idToHuman);
    placeShip("Submarine", SIZE_SUBMARINE, SUBMARINE, placer);
    printBoard(placer->board, idToHuman);
    placeShip("Destroyer", SIZE_DESTROYER, DESTROYER, placer);
    printBoard(placer->board, idToHuman);
    placeShip("Battleship", SIZE_BATTLESHIP, BATTLESHIP, placer);
    printBoard(placer->board, idToHuman);
    placeShip("Aircraft Carrier", SIZE_AIRCRAFT_CARRIER, AIRCRAFT_CARRIER, placer);
    printBoard(placer->board, idToHuman);
    tmp = readChar("Accept this board [Y/N]? ", "", "yYnN");
  } while (tmp == 'n' || tmp == 'N');
  write(wfd, placer->board, SIZE*SIZE);
}

static char* getStatus(Placer* placer, Shot s)
{
  switch(placer->board[s.row][s.col])
    {
    case OPEN_WATER:
      return "Miss.";
    case PATROL_BOAT:
      return ++placer->boats[0] == SIZE_PATROL_BOAT?
        "SINK!":"Hit!";
    case SUBMARINE:
      return ++placer->boats[1] == SIZE_SUBMARINE?
        "SINK!":"Hit!";
    case DESTROYER:
      return ++placer->boats[2] == SIZE_DESTROYER?
        "SINK!":"Hit!";
    case BATTLESHIP:
      return ++placer->boats[3] == SIZE_BATTLESHIP?
        "SINK!":"Hit!";
    case AIRCRAFT_CARRIER:
      return ++placer->boats[4] == SIZE_AIRCRAFT_CARRIER?
        "SINK!":"Hit!";
    case SHOT(OPEN_WATER):
    case SHOT(PATROL_BOAT):
    case SHOT(SUBMARINE):
    case SHOT(DESTROYER):
    case SHOT(BATTLESHIP):
    case SHOT(AIRCRAFT_CARRIER):
      return "Rehit.";
    default:
      return "?";
      
    }
}

void markAsHit(Placer* placer, Shot s) {
   placer->board[s.row][s.col] ^= -1;
}

void registerShot(Placer* placer, Shot s)
{
  printf("Shot: (%c, %hu): %s\n", ((char) s.col) + 'A', s.row, getStatus(placer, s));
  markAsHit(placer, s);
  printBoard(placer->board, idToHuman);
}
