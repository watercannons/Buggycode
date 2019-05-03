#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <battleship.h>

#ifdef REPLAY
const char* thisProcessStringID = "dumb-ai";
#include <replay.h>
#include <fd_replay.h>
#include <replay_undef.h>
#endif /* REPLAY */


void printHelp()
{
   fprintf(stderr, "Usage: player readFD writeFD\n");
   exit(EXIT_FAILURE);
}

int getFD(char* fd)
{
   int res;
   if (!sscanf(fd, "%d", &res))
   {
      printHelp();
   }
   return res;
}

int getSignal(int rfd)
{
   int sig, bytes;
   if ((bytes = read(rfd, &sig, sizeof(sig))) != sizeof(sig))
   {
      fprintf(stderr, "Read error at %s:%d - Expected %zu bytes, got %d.\n",
         __FILE__, __LINE__, sizeof(sig), bytes);
      exit(EXIT_FAILURE);
   }
   return sig;
}

void placePatrol(char board[SIZE][SIZE])
{
   board[SIZE-1][SIZE-1] = PATROL_BOAT;
   board[SIZE-1][SIZE-2] = PATROL_BOAT;
}

void placeSubmarine(char board[SIZE][SIZE])
{
   board[SIZE-2][SIZE-1] = SUBMARINE;
   board[SIZE-2][SIZE-2] = SUBMARINE;
   board[SIZE-2][SIZE-3] = SUBMARINE;
}

void placeDestroyer(char board[SIZE][SIZE])
{
   board[SIZE-3][SIZE-1] = DESTROYER;
   board[SIZE-3][SIZE-2] = DESTROYER;
   board[SIZE-3][SIZE-3] = DESTROYER;
}

void placeBattleship(char board[SIZE][SIZE])
{
   board[SIZE-4][SIZE-1] = BATTLESHIP;
   board[SIZE-4][SIZE-2] = BATTLESHIP;
   board[SIZE-4][SIZE-3] = BATTLESHIP;
   board[SIZE-4][SIZE-4] = BATTLESHIP;
}

void placeAirCarrier(char board[SIZE][SIZE])
{
   board[SIZE-5][SIZE-1] = AIRCRAFT_CARRIER;
   board[SIZE-5][SIZE-2] = AIRCRAFT_CARRIER;
   board[SIZE-5][SIZE-3] = AIRCRAFT_CARRIER;
   board[SIZE-5][SIZE-4] = AIRCRAFT_CARRIER;
   board[SIZE-5][SIZE-5] = AIRCRAFT_CARRIER;
}

void newGame(char board[SIZE][SIZE], int wfd, Shot* shot)
{
   shot->row = SIZE-1;
   shot->col = SIZE-1;
   memset(board, OPEN_WATER, SIZE*SIZE);
   placePatrol(board);
   placeSubmarine(board);
   placeDestroyer(board);
   placeBattleship(board);
   placeAirCarrier(board);
   write(wfd, board, SIZE*SIZE);
}

Shot fireShot(Shot shot, int wfd)
{
   if (!(shot.col = (shot.col + 1) % SIZE))
   {
      shot.row = (shot.row + 1) % SIZE;
   }
   write(wfd, &shot, sizeof(shot));
   return shot;
}

void processSignal(int sig, char board[SIZE][SIZE], int wfd, Shot* last)
{
   switch (sig)
   {
      case NEW_GAME:
         newGame(board, wfd, last);
      break;
      case SHOT_REQUEST:
         *last = fireShot(*last, wfd);
      break;
   }
}

void playGame(int rfd, int wfd)
{
   int sig;
   Shot last;
   char board[SIZE][SIZE];
   do
   {
      processSignal(sig = getSignal(rfd), board, wfd, &last);
   } while (sig != MATCH_OVER);
   close(rfd);
   close(wfd);
}

int main(int argn, char** args)
{
#ifdef REPLAY
  init_replay(&argn, (const char ***) &args);
#endif /* REPLAY */
   if (argn != 3)
   {
      printHelp();
   }
   playGame(getFD(args[1]), getFD(args[2]));
   return 0;
}
