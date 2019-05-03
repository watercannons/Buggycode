#include "common.h"
#include <stdio.h>
#include <limits.h>

#ifdef REPLAY
#include <replay.h>
#include <fd_replay.h>
#include <replay_undef.h>
#endif /* REPLAY */


void clearline()
{
  while (getchar() != '\n');
}

static void printHeader()
{
  char col;
  for (col = 'A'; col < 'A' + SIZE; col++)
    {
      printf(" %c ", col);
    }
}

void printBoard(unsigned char board[SIZE][SIZE], char* (*idToHuman)(char))
{
  char sep = ' ';
  int row, col;
  printf("[ ");
  printHeader();
  for (row = 0; row < SIZE; row++)
    {
      printf("%c\n%hu [", sep, row);
      printf("%s", idToHuman(board[row][0]));
      for (col = 1; col < SIZE; col++)
        {
          printf(", %s", idToHuman(board[row][col]));
        }
      printf("]");
      sep = ',';
    }
  printf("\n]\n");
}

static unsigned short toNum(char col)
{
  if (col >= 'A' && col <= ((char) SIZE) + 'A')
    {
      return col - 'A';
    }
  else if (col >= 'a' && col <= ((char) SIZE) + 'a')
    {
      return col - 'a';
    }
  else
    {
      return USHRT_MAX;
    }
}

void getCoordinate(Shot* p, int col, int row)
{
  char tmp;
  printf("\nEnter column: [A-%c]: ", ((char) col) + 'A');
  while (!(scanf(" %c", &tmp) && (p->col = toNum(tmp)) != USHRT_MAX && p->col <= col))
    {
      printf("Please enter a column between [A-%c]: ", ((char) col) + 'A');
      clearline();
    }
  toNum(tmp);
  clearline();
  printf("\nEnter row: [0-%d]: ", row);
  while (!(scanf(" %hu", &p->row) && p->row <= row))
    {
      printf("Please enter a row between [0-%d]: ", row);
      clearline();
    }
  clearline();
}
