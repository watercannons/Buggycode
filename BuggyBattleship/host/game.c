#include <battleship.h>
#include "game.h"
#include "const.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <libgen.h>

#ifdef REPLAY
#include <replay.h>
#include <fd_replay.h>
#include <replay_undef.h>
#endif /* REPLAY */

void getSig(int rfd, void* targ, unsigned int size)
{
   int i = 0, tmp;
   do
     tmp = read(rfd, ((char*)targ)+i, size);
   while ((i += tmp) < size);
}

void sendSig(int fd, int sig)
{
  write(fd, &sig, sizeof(sig));
}

void sendShot(int fd, Shot s)
{
  write(fd, &s, sizeof(s));
}

void initPlayer(Player* player)
{
   sendSig(player->pipes[WRITE], NEW_GAME);
   player->shots = player->misses = player->hit = player->sunk = 0;
   memset(player->boats, 0, NUMBER_OF_SHIPS*sizeof(unsigned short));
   getSig(player->pipes[READ], player->board, sizeof(char)*SIZE*SIZE);
}

void initGame(Player p[2])
{
  initPlayer(&p[0]);
  initPlayer(&p[1]);
}

void markAsHit(char board[SIZE][SIZE], Shot s) {
   board[s.row][s.col] = HIT;
}

int checkHit(Player* active, Player* passive, Shot s)
{
   int res;
   if (s.row >= SIZE || s.col >= SIZE
      || passive->board[s.row][s.col] == OPEN_WATER)
   {
      active->misses++;
      return MISS;
   }
   active->hit++;
   res = HIT;
   switch (passive->board[s.row][s.col])
   {
      case PATROL_BOAT:
         res = ++active->boats[0] == SIZE_PATROL_BOAT?
           SINK : HIT;
      break;
      case SUBMARINE:
         res = ++active->boats[1] == SIZE_SUBMARINE?
           SINK : HIT;
      break;
      case DESTROYER:
         res = ++active->boats[2] == SIZE_DESTROYER?
           SINK : HIT;
      break;
      case BATTLESHIP:
         res = ++active->boats[3] == SIZE_BATTLESHIP?
           SINK : HIT;
      break;
      case AIRCRAFT_CARRIER:
         res = ++active->boats[4] == SIZE_AIRCRAFT_CARRIER?
           SINK : HIT;
      break;
   }
   markAsHit(passive->board, s);
   active->sunk += res == SINK;
   return res;
}

void turn(Player* active, Player* passive, int d)
{
   Shot s;
   int isHit;
   sendSig(active->pipes[WRITE], SHOT_REQUEST);
   getSig(active->pipes[READ], &s, sizeof(s));
   sendSig(passive->pipes[WRITE], OPPONENTS_SHOT);
   sendShot(passive->pipes[WRITE], s);
   active->shots++;
   sendSig(active->pipes[WRITE], SHOT_RESULT);
   isHit = checkHit(active, passive, s);
   sendSig(active->pipes[WRITE], isHit);
   if (d)
   {
      char* hitWord = isHit == MISS? "Miss" : (isHit == HIT? "HIT!" : "SINK!");
      printf("%16s: shot[%2u][%2u], %5s, shots:%3u, "
         "misses:%2u, hits:%2u, sunk:%u\n",
         basename(active->name), s.row, s.col, hitWord,
         active->shots, active->misses, active->hit, active->sunk);
      fflush(stdout);
   }
}

void tallyScore(Player p[2], int d, int i)
{
   if (d)
      printf("\nGame %d Results: ", i);
   if (p[0].sunk < NUMBER_OF_SHIPS && p[1].sunk < NUMBER_OF_SHIPS)
   {
      if (d)
         printf("No winner within %d shots\n", MAX_SHOTS);
      p[0].loss++;
      p[1].loss++;
   }
   else if (p[0].sunk < NUMBER_OF_SHIPS)
   {
      if (d)
         printf("%s won!\n", basename(p[1].name));
      p[0].loss++;
      p[1].win++;
   }
   else if (p[1].sunk < NUMBER_OF_SHIPS)
   {
      if (d)
         printf("%s won!\n", basename(p[0].name));
      p[0].win++;
      p[1].loss++;
   }
   else
   {
      if (d)
         printf("Draw\n");
      p[0].tie++;
      p[1].tie++;
   }

   if (d)
   {
      printf("%16s: %u shots, %u hits, and %u sinks\n",
         basename(p[0].name), p[0].shots, p[0].hit, p[0].sunk);
      printf("%16s: %u shots, %u hits, and %u sinks\n",
         basename(p[1].name), p[1].shots, p[1].hit, p[1].sunk);
   }
}

void playGame(Player p[2], int d, int i)
{
   if (d)
      printf("\nGame %d Details:\n", i);
   initGame(p);
   do
   {
      turn(&p[0], &p[1], d);
      turn(&p[1], &p[0], d);
   } while (p[0].sunk < NUMBER_OF_SHIPS && p[1].sunk < NUMBER_OF_SHIPS && p[1].shots < MAX_SHOTS);
   tallyScore(p, d, i);
}

void closeChild(Player p)
{
   close(p.pipes[WRITE]);
   close(p.pipes[READ]);
}
