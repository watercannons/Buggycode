#include "game.h"
#include "const.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <libgen.h>

#ifdef REPLAY
const char* thisProcessStringID = "host";
#include <replay.h>
#include <fork_replay.h>
#include <replay_undef.h>
#endif /* REPLAY */

void printHelp()
{
   fprintf(stderr, "Usage: battleship [-gN|-d] player1 player2\n");
   exit(EXIT_FAILURE);
}

typedef struct
{
   int g;
   int d;
   char* player[2];
} Args;

/*
 * Parse out if argument is a player or a flag.
 * 
 * @param res The argument struct to output information.
 * @param arg The argument to parse
 * @param c   The number of players currently counted.
 * @return The number of players parsed thus far (Will be c or c+1)
 *
 * Postcondition: res will contain the information parsed
 */
int parseArg(Args* res, char* arg, int c)
{
   if (arg[0] == '-')
      if (arg[1] == 'd')
        res->d = 1;
      else if (!sscanf(arg+1, "g%d", &res->g) || res->g <= 0)
        printHelp();
   else if (c < 2)
      res->player[c++] = arg;
   else
      printHelp();
   return c;
}

Args getArgs(int argn, char** args)
{
   Args res;
   int i, c = 0;
   res.g = 3;
   res.d = 0;
   for (i = 1; i < argn; i++)
      c = parseArg(&res, args[i], c);
   if (c != 2)
      printHelp();
   return res;
}

/*
 * Creates a new child process and sets up read/write fd's in
 * player struct to communicate with the new process.
 * 
 * @param p the player struct containing information for the new process.
 * 
 * Postcondition: After this function call, p->pipes[READ] will be the 
 * file descriptor to receive information from the child process.
 * 
 * Postcondition: After this function call, p->pipes[WRITE] will be the
 * file descriptor to send signals to child process.
 */
void forkPlayer(Player* p)
{  
   int upStream[2], downStream[2];
   pipe(upStream);
   pipe(downStream);
   if (!(p->pid = fork()))
   {
      char r[5], w[5];
      sprintf(r, "%d", downStream[READ]);
      sprintf(w, "%d", upStream[WRITE]);
      execl(p->name, p->name, r, w, NULL);
   }
   else
   {
      p->pipes[WRITE] = upStream[WRITE];
      p->pipes[READ] = downStream[READ];
   }
}

void printEnd(Player p[2], int i)
{
   if (p[0].win > p[1].win)
      printf("\nMatch Results: %s won!\n", basename(p[0].name));
   else if (p[0].win < p[1].win)
      printf("\nMatch Results: %s won!\n", basename(p[1].name));
   else
      printf("\nMatch Results: No winner in %d games\n", i);
   printf("%16s: %u wins, %u draws, and %u losses\n",
      basename(p[0].name), p[0].win, p[0].tie, p[0].loss);
   printf("%16s: %u wins, %u draws, and %u losses\n",
      basename(p[1].name), p[1].win, p[1].tie, p[1].loss);
}

int main(int argn, char** args)
{
   int i, status;
   Args arg;
   Player p[2];
#ifdef REPLAY
  init_replay(&argn, (const char ***) &args);
#endif /* REPLAY */
   arg = getArgs(argn, args);
   p[0].name = arg.player[0];
   p[0].win = p[0].loss = p[0].tie = 0;
   p[1].name = arg.player[1];
   p[1].win = p[1].loss = p[1].tie = 0;
   forkPlayer(&p[0]);
   forkPlayer(&p[1]);
   for (i = 1; i <= arg.g; i++)
      playGame(p, arg.d, i);
   closeChild(p[0]);
   closeChild(p[1]);
   printEnd(p, arg.g);
   waitpid(p[0].pid, &status, 0);
   waitpid(p[1].pid, &status, 0);
   return 0;
}
