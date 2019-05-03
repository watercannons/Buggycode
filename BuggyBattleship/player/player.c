#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <battleship.h>
#include "placer.h"
#include "shooter.h"

#ifdef REPLAY
const char* thisProcessStringID = "player";
#include <fd_replay.h>
#include <replay.h>
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
      fprintf(stderr, "Read error at %s:%d - Expected %lu bytes, got %d.\n",
         __FILE__, __LINE__, sizeof(sig), bytes);
      exit(EXIT_FAILURE);
   }
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
  clearShooter(shooter);
  clearPlacer(placer);
  placeBoats(placer, wfd);
}

Shot fireShot(int wfd)
{
   Shot s;
   printf("\nEnter column: [A-%c]: ", ((char) SIZE) + 'A');
   scanf(" %hu", &s.col);
   printf("\nEnter row: [0-%d]: ", SIZE);
   scanf(" %hu", &s.row);
   write(wfd, &s, sizeof(Shot));
   return s;
}

void playGame(int rfd, int wfd)
{
   Shooter* shooter = newShooter();
   Placer* placer = newPlacer();
   Shot s;
   int sig;
   do
   {
     switch (sig = getSignal(rfd))
       {
       case NEW_GAME:
         printf("New Game!\n");
         newGame(wfd, shooter, placer);
         break;
       case SHOT_REQUEST:
         s = nextShot(shooter);
         write(wfd, &s, sizeof(Shot));
         break;
       case SHOT_RESULT:
         registerResult(shooter, getSignal(rfd));
         break;
       case OPPONENTS_SHOT:
         registerShot(placer, getShot(rfd));
         break;
       }
   } while (sig != MATCH_OVER);
   printf("Match over!\n");
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
