#include "shooter.h"
#include "common.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct shooter {
  unsigned char board[SIZE][SIZE];
  Shot lastShot;
};

Shooter* newShooter(void)
{
  Shooter* s = malloc(sizeof(Shooter));
  if (!s)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  return s;
}

void clearShooter(Shooter* s)
{
  memset(s->board, UNKNOWN, SIZE*SIZE);
}

static char* idToHuman(char c)
{
  switch (c)
    {
    case MISS:
      return ANSI_COLOR_WHITE "m" ANSI_COLOR_RESET;
    case HIT:
      return ANSI_COLOR_MAGENTA "H" ANSI_COLOR_RESET;
    case SINK:
      return ANSI_COLOR_RED "S" ANSI_COLOR_RESET;
    case UNKNOWN:
    default:
      return ANSI_COLOR_GREEN "?" ANSI_COLOR_RESET;
    }

}

Shot nextShot(Shooter* shooter)
{
  printBoard(shooter->board, idToHuman);
  getCoordinate(&shooter->lastShot, SIZE - 1, SIZE - 1);
  return shooter->lastShot;
}

void registerResult(Shooter* s, int res)
{
  s->board[s->lastShot.row][s->lastShot.col] = res;
  printBoard(s->board, idToHuman);
}
