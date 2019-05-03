#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include<battleship.h>
#include "placer.h"
#include "shooter.h"

#ifdef REPLAY
const char* thisProcessStringID = "ai";
#include <replay.h>
#include <fd_replay.h>
#include <replay_undef.h>
#endif /* REPLAY */

#define HORIZONTAL 0
#define VERTICAL 1

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
   int sig;
   read(rfd, &sig, sizeof(sig));
   return sig;
}

Shot getShot(int rfd)
{
   Shot s;
   read(rfd, &s, sizeof(s));
   return s;
}

void newGame(int wfd, Shooter* shooter, Placer* placer)
{
   unsigned char board[SIZE][SIZE];
   clearShooter(shooter);
   clearPlacer(placer);
   makeBoard(placer, board);
   write(wfd, board, SIZE*SIZE);
}

void playGame(int rfd, int wfd)
{
   int sig;
   Shooter* shooter = newShooter();
   Placer* placer = newPlacer();
   srand(time(NULL));
   do
   {
      switch (sig = getSignal(rfd))
      {
         case NEW_GAME:
            newGame(wfd, shooter, placer);
         break;
         case SHOT_REQUEST:
            write(wfd, nextShot(shooter), sizeof(Shot));
         break;
         case SHOT_RESULT:
            processResult(shooter, getSignal(rfd));
         break;
         case OPPONENTS_SHOT:
            processShot(placer, getShot(rfd));
         break;
      }
   } while (sig != MATCH_OVER);
   close(rfd);
   close(wfd);
   deleteShooter(shooter);
   deletePlacer(placer);
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
