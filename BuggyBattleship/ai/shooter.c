#include <battleship.h>
#include "shooter.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Search for ships based on probability
 */
#define SCATTER 0
/*
 * Target Right Uncertain
 */
#define TARG_R_U 1
/*
 * Target Right Horizontal
 */
#define TARG_R_H 2
/*
 * Target Down Uncertain
 */
#define TARG_D_U 3
/*
 * Target Down Vertical
 */
#define TARG_D_V 4
/*
 * Target Left Uncertain
 */
#define TARG_L_U 5
/*
 * Target Left Horizontal
 */
#define TARG_L_H 6
/*
 * Target Up Down Vertical
 */
#define TARG_U_V 8
/*
 * No Target up uncertain: If target up, all options exhausted
 */
/*
 * Shoot near ships already targeted.
 * Used when all possible targets are exhuasted.
 */
#define RE_TARG 9

#define MAX(_X,_Y) ((_X) > (_Y)? (_X):(_Y))

struct Shooter
{
   Shot shot;
   Shot prevShot;
   List* targets;
   List* sinks;
   unsigned char board[SIZE][SIZE];
   unsigned short state;
};

typedef struct
{
   Shot end;
   Shot start;
   unsigned char isHorizontal;
   unsigned char length;
} Sink;

/*
 * Initalize a new shooter object.
 *
 * @return A new shooter object
 */
Shooter* newShooter()
{
   Shooter* res = calloc(1, sizeof(Shooter));
   clearShooter(res);
   return res;
}

int getBoardVal(Shooter* s, Shot shot)
{
   return shot.row > SIZE || shot.col > SIZE?
      MISS : s->board[shot.row][shot.col];
}

/*
 * Checks if the shooter object has sunk the air carrier.
 *
 * @param s The shooter to check for air carrier sink
 * @return 1 if the air carrier is sunk, 0 otherwise
 */
int hasSunk(Shooter* s, int size)
{
   Sink* sink;
   Node* n = s->sinks->tail;
   int cnt = 0;
   while (n)
   {
      sink = n->value;
      if (sink->length == size && (size != 3 || ++cnt == 2))
         return 1;
      n = n->next;
   }
   return 0;
}

/*
 * Check if a boat would fit at the given position horizontally.
 *
 * @param board The current known board to check against
 * @param x the x cordinate of the possible position (far left)
 * @param y the y cordinate of the possible position (far top)
 * @param size The size of the boat
 * @returns -1 if it would fit, otherwise the offset from x at which it fails
 */
int checkPosHorz(unsigned char board[SIZE][SIZE], int x, int y, int size)
{
   int i;
   if (x + size > SIZE)
      return SIZE - x;
   for (i = x; i < x + size; i++)
      if (board[i][y] != OPEN_WATER)
         return i;
   return -1;
}

/*
 * Check if a boat would fit at the given position vertically.
 *
 * @param board The current known board to check against
 * @param x the x cordinate of the possible position (far left)
 * @param y the y cordinate of the possible position (far top)
 * @param size The size of the boat
 * @returns -1 if it would fit, otherwise the offset from y at which it fails
 */
int checkPosVert(unsigned char board[SIZE][SIZE], int x, int y, int size)
{
   int i;
   if (y + size > SIZE)
      return SIZE - y;
   for (i = y; i < y + size; i++)
      if (board[x][i] != OPEN_WATER)
         return i;
   return -1;
}

/*
 * Fills each cell in a table with the number of unique ship configurations
 * which could fit in that cell.
 *
 * @param s The shooter containing the board of known ships.
 */
void addPossible(Shooter* s, unsigned char probs[SIZE][SIZE], int size)
{
   int x, y, i;
   if (size == 2 && hasSunk(s, size))
      return;
   for (x = 0; x < SIZE; x++)
      for (y = 0; y < SIZE; y++)
      {
         if (checkPosHorz(s->board, x, y, size) < 0)
            for (i = x; i < x+size; i++)
               probs[i][y]++;
         if (checkPosVert(s->board, x, y, size) < 0)
            for (i = y; i < y+size; i++)
               probs[x][i]++;
      }
}

/*
 * Sets the next shot to the target most likely to contain a ship.
 *
 * @param s The shooter containing the most recent information
 * @return The number of ship configurations which would fit in the
 * selected cell.
 */
int setProbableShot(Shooter* s)
{
   unsigned char probs[SIZE][SIZE];
   unsigned char max = 0;
   Shot shot;
   shot.row = 0;
   shot.col = 0;
   memset(probs, 0, SIZE*SIZE*sizeof(unsigned char));
   addPossible(s, probs, SIZE_PATROL_BOAT);
   addPossible(s, probs, SIZE_SUBMARINE);
   addPossible(s, probs, SIZE_DESTROYER);
   addPossible(s, probs, SIZE_BATTLESHIP);
   addPossible(s, probs, SIZE_AIRCRAFT_CARRIER);
   for (shot.row = 0; shot.row < SIZE; shot.row++)
   {
      for (shot.col = 0; shot.col < SIZE; shot.col++)
      {
         if (probs[shot.row][shot.col] > max)
         {
            max = probs[shot.row][shot.col];
            s->shot = shot;
         }
      }
   }
   return max;
}

/*
 * Searches for the next reasonable shot to the left the targeted shot and sets
 * the next shot accordingly.
 *
 * @param s The shooter containing the current information
 * @return 1 if a reasonable shot is found, 0 otherwise
 */
int findLeft(Shooter* s)
{
   unsigned char cell;
   Shot shot;
   if (!s->targets->size)
      return 0;
   shot = *(Shot*) listGet(s->targets, 0);
   while (--shot.col < SIZE &&
      (cell = s->board[shot.row][shot.col]) != MISS && cell != SINK)
   {
      if (s->board[shot.row][shot.col] == OPEN_WATER)
      {
         s->shot = shot;
         return 1;
      }
   }
   return 0;
}

/*
 * Searches for the next reasonable shot to the right the targeted shot and sets
 * the next shot accordingly.
 *
 * @param s The shooter containing the current information
 * @return 1 if a reasonable shot is found, 0 otherwise
 */
int findRight(Shooter* s)
{
   unsigned char cell;
   Shot shot;
   if (!s->targets->size)
      return 0;
   shot = *(Shot*) listGet(s->targets, 0);
   while (++shot.col < SIZE &&
      (cell = s->board[shot.row][shot.col]) != MISS && cell != SINK)
   {
      if (s->board[shot.row][shot.col] == OPEN_WATER)
      {
         s->shot = shot;
         return 1;
      }
   }
   return 0;
}

/*
 * Searches for the next reasonable shot below the targeted shot and sets the
 * next shot accordingly.
 *
 * @param s The shooter containing the current information
 * @return 1 if a reasonable shot is found, 0 otherwise
 */
int findDown(Shooter* s)
{
   unsigned char cell;
   Shot shot;
   if (!s->targets->size)
      return 0;
   shot = *(Shot*) listGet(s->targets, 0);
   while (++shot.row < SIZE &&
      (cell = s->board[shot.row][shot.col]) != MISS && cell != SINK)
   {
      if (s->board[shot.row][shot.col] == OPEN_WATER)
      {
         s->shot = shot;
         return 1;
      }
   }
   return 0;
}

/*
 * Searches for the next reasonable shot above the targeted shot and sets the
 * next shot accordingly.
 *
 * @param s The shooter containing the current information
 * @return 1 if a reasonable shot is found, 0 otherwise
 */
int findUp(Shooter* s)
{
   unsigned char cell;
   Shot shot;
   if (!s->targets->size)
      return 0;
   shot = *(Shot*) listGet(s->targets, 0);
   while (--shot.row < SIZE &&
      (cell = s->board[shot.row][shot.col]) != MISS && cell != SINK)
   {
      if (s->board[shot.row][shot.col] == OPEN_WATER)
      {
         s->shot = shot;
         return 1;
      }
   }
   return 0;
}

/*
 * Given a shooter targeting a ship in an unknown orientation, finds the next
 * reasonable shot to take and returns the predicted orientation.
 *
 * @param s The shooter containing the current information
 * @return The state for the predicted orientation
 */
int findNextState(Shooter* s)
{
   switch(s->state)
   {
      case SCATTER:
         if (s->targets->size == 0)
            return SCATTER;
      case RE_TARG:
         if (findRight(s))
            return TARG_R_U;
      case TARG_R_U:
         if (findDown(s))
            return TARG_D_U;
      case TARG_D_U:
         if (findLeft(s))
            return TARG_L_U;
      case TARG_L_U:
         if (findUp(s))
            return TARG_U_V;
         else
         {
            free(listDelete(s->targets, 0));
            s->state = SCATTER;
            return findNextState(s);
         }
   }
   return SCATTER;
}

/*
 * Creates a pointer to a Shot matching the given.
 *
 * @param shot The Shot to copy to the pointer
 * @return A pointer to a cloned Shot
 */
Shot* toPtr(Shot shot)
{
   Shot* res = calloc(1, sizeof(Shot));
   *res = shot;
   return res;
}

/*
 * Chooses the next shot to maximum adjacent hits.
 *
 * Used in the case that a ship cannot be found and must therefore
 * have already been hit.
 *
 * @param s The shooter containing the most recent information
 */
void setRetargetedShot(Shooter* s)
{
   const int expected[] = {SIZE_AIRCRAFT_CARRIER, SIZE_BATTLESHIP,
      SIZE_DESTROYER, SIZE_SUBMARINE, SIZE_PATROL_BOAT};
   Node* n = s->sinks->head;
   Sink* sink;
   int i = 0;
   while (n)
   {
      sink = n->value;
      if (sink->length < expected[i])
         i++;
      else if (sink->length == expected[i])
      {
         i++;
         if (getBoardVal(s, sink->start) == HIT)
            listAdd(s->targets, toPtr(sink->start));
         if (getBoardVal(s, sink->end) == HIT)
            listAdd(s->targets, toPtr(sink->end));
         n = n->next;
      }
      else
      {
         int lng = sink->length;
         Node* bad = n;
         while (bad && (sink = bad->value)->length == lng)
         {
            if (getBoardVal(s, sink->start) == HIT)
               listAdd(s->targets, toPtr(sink->start));
            if (getBoardVal(s, sink->end) == HIT)
               listAdd(s->targets, toPtr(sink->end));
            bad = bad->last;
         }
         n = n->next;
      }
   }
   s->state = findNextState(s);
}

void chooseBetterShot(Shooter* s)
{
   Shot shot = s->shot, seek;
   int maxAdj = -1, adj;
   if (shot.row >= SIZE || shot.col >= SIZE
      || getBoardVal(s, shot) != OPEN_WATER)
   {
      for (seek.row = 0; seek.row < SIZE; seek.row++)
      {
         for (seek.col = 0; seek.col < SIZE; seek.col++)
         {
            if (getBoardVal(s, seek) != OPEN_WATER)
               continue;
            adj = 0;
            adj += seek.row > 0 && s->board[seek.row - 1][seek.col] == HIT;
            adj += seek.col > 0 && s->board[seek.row][seek.col - 1] == HIT;
            adj += seek.row + 1 < SIZE &&
               s->board[seek.row + 1][seek.col] == HIT;
            adj += seek.col + 1 < SIZE &&
               s->board[seek.row][seek.col + 1] == HIT;
            if (adj >= maxAdj)
            {
               maxAdj = adj;
               shot = seek;
            }
         }
      }
      s->shot = shot;
   }
}

/*
 * Gets the next reasonable shot to fire at.
 *
 * @param s The shooter containing the current information
 * @return The shot to take
 */
Shot* nextShot(Shooter* s)
{
   if (s->state != SCATTER && s->shot.row == s->prevShot.row
      && s->shot.col == s->prevShot.col)
   {
      s->state = SCATTER;
      while (s->targets->size)
         free(listDelete(s->targets, 0));
   }
   s->prevShot = s->shot;
   switch (s->state)
   {
      case SCATTER:
         if (setProbableShot(s))
           break;
      case RE_TARG:
         setRetargetedShot(s);
   }
   chooseBetterShot(s);
   return &s->shot;
}

int cmpShot(const void* a, const void* b)
{
   Shot* as = (Shot*) a;
   Shot* bs = (Shot*) b;
   return ((as->row - bs->row) << sizeof(short)) | (as->col - bs->col);
}

/*
 * Sets up all hits to the right of the last shot as a possible targets.
 *
 * @param s The shooter containing current information
 */
void queueHorizontal(Shooter* s)
{
   Shot shot = s->shot;
   while (++shot.col < SIZE && s->board[shot.row][shot.col] != MISS)
   {
      if (s->board[shot.row][shot.col] == SINK)
      {
         s->state = s->targets->size? TARG_D_U : SCATTER;
         return;
      }
      listAdd(s->targets, toPtr(shot));
   }
}

/*
 * Sets up all hits below the last shot as a possible targets.
 *
 * @param s The shooter containing current information
 */
void queueVertical(Shooter* s)
{
   Shot shot = s->shot;
   while (++shot.row < SIZE && s->board[shot.row][shot.col] != MISS)
   {
      if (s->board[shot.row][shot.col] == SINK)
      {
         s->state = s->targets->size? TARG_R_U : SCATTER;
         return;
      }
      listAdd(s->targets, toPtr(shot));
   }
}

/*
 * Adjusts the known information given that the last show was a miss.
 *
 * @param shooter The shooter containing the current information
 */
void processMiss(Shooter* shooter)
{
   switch (shooter->state)
   {
      case TARG_R_U:
         shooter->state = findNextState(shooter);
      return;
      case TARG_R_H:
         shooter->state = TARG_L_H;
         if (!findLeft(shooter))
         {
            while (--(shooter->shot.col) < SIZE &&
               shooter->board[shooter->shot.row][shooter->shot.col] == HIT);
            free(listDelete(shooter->targets, 0));
            queueHorizontal(shooter);
            if (findDown(shooter))
               shooter->state = TARG_D_V;
            else if (findUp(shooter))
               shooter->state = TARG_U_V;
         }
      return;
      case TARG_D_V:
         shooter->state = TARG_U_V;
         if (!findUp(shooter))
         {
            while (--(shooter->shot.row) < SIZE &&
               shooter->board[shooter->shot.row][shooter->shot.col] == HIT);
            free(listDelete(shooter->targets, 0));
            queueVertical(shooter);
            if (findRight(shooter))
               shooter->state = TARG_R_H;
            else if (findLeft(shooter))
               shooter->state = TARG_L_H;
         }
      return;
      case TARG_D_U:
      case TARG_L_U:
         shooter->state = findNextState(shooter);
      return;
      case TARG_L_H:
         free(listDelete(shooter->targets, 0));
         if (shooter->targets->size)
            shooter->state = TARG_R_U;
         else
         {
            queueHorizontal(shooter);
            if (findDown(shooter))
               shooter->state = TARG_D_V;
            else if (findUp(shooter))
               shooter->state = TARG_U_V;
         }
      return;
      case TARG_U_V:
         free(listDelete(shooter->targets, 0));
         if (shooter->targets->size)
            shooter->state = TARG_R_U;
         else
         {
            queueVertical(shooter);
            if (findRight(shooter))
               shooter->state = TARG_R_H;
            else if (findLeft(shooter))
               shooter->state = TARG_L_H;
         }
      return;
      case SCATTER:
      case RE_TARG:return;
   }
}

/*
 *Adjusts the known information given that the last show was a hit.
 *
 * @param shooter The shooter containing the current information
 */
void processHit(Shooter* shooter)
{
   switch (shooter->state)
   {
      case TARG_R_U:
         shooter->state = TARG_R_H;
      case TARG_R_H:
         if (!findRight(shooter))
            processMiss(shooter);
      return;
      case TARG_D_U:
         shooter->state = TARG_D_V;
      case TARG_D_V:
         if (!findDown(shooter))
            processMiss(shooter);
      return;
      case TARG_L_U:
         shooter->state = TARG_L_H;
      case TARG_L_H:
         if (!findLeft(shooter))
         {
            while (--shooter->shot.col < SIZE &&
               shooter->board[shooter->shot.row][shooter->shot.col] == HIT);
            processMiss(shooter);
         }
      return;
      case TARG_U_V:
         if (!findUp(shooter))
         {
            while (--shooter->shot.row < SIZE &&
               shooter->board[shooter->shot.row][shooter->shot.col] == HIT);
            processMiss(shooter);
         }
      return;
      case SCATTER:
      case RE_TARG:
         listAdd(shooter->targets, toPtr(shooter->shot));
         shooter->state = findNextState(shooter);
      return;
   }
}

int cmpSink(const void* a, const void* b)
{
   return ((Sink*) b)->length - ((Sink*) a)->length;
}

/*
 * Adds the last shot to the list of sunk ships.
 *
 * @param s A shooter whose last shot sunk a ship and maintains
 * all it's state information
 */
void addSink(Shooter* s)
{
   Node* n = s->sinks->head;
   Sink* sink = calloc(1, sizeof(Sink));
   Sink* other;
   Shot start = s->shot, end = start;
   sink->isHorizontal = s->state == TARG_R_U || s->state == TARG_R_H
      || s->state == TARG_L_U || s->state == TARG_L_H;
   if (s->state == SCATTER)
   {
      if (s->board[start.row][start.col + 1] == HIT
         || s->board[start.row][start.col - 1] == HIT)
      {
         if (s->board[start.row + 1][start.col] == HIT
            || s->board[start.row - 1][start.col] == HIT)
         {
            sink->length = 1;
            sink->start = start;
            sink->end = sink->start;
         }
         else
         {
            sink->isHorizontal = 1;
         }
      }
      else
      {
         sink->isHorizontal = 0;
      }
   }
   if (sink->isHorizontal)
   {
      while (++end.col < SIZE && getBoardVal(s, end) == HIT);
      --end.col;
      while (--start.col < SIZE && getBoardVal(s, start) == HIT);
      start.col++;
      sink->start = start;
      sink->end = end;
      while (n)
      {
         other = n->value;
         if (!other->isHorizontal && other->start.col >= start.col
            && other->start.col <= end.col)
         {
            if (other->start.col == start.col && end.col - start.col > 3)
               sink->start.col = start.col - 1;
            else if (other->start.col == end.col && end.col - start.col > 3)
               sink->end.col = end.col - 1;
            if (other->start.row == end.row && other->length > 3)
            {
               ++other->start.row;
               --other->length;
            }
            else if (other->end.row == end.row && other->length > 3)
            {
               --other->end.row;
               --other->length;
            }
         }
         n = n->next;
      }
      sink->length = end.col - start.col + 1;
   }
   else
   {
      while (++end.row < SIZE && getBoardVal(s, end) == HIT);
      --end.row;
      while (--start.row < SIZE && getBoardVal(s, start) == HIT);
      start.row++;
      sink->start = start;
      sink->end = end;
      while (n)
      {
         other = n->value;
         if (other->isHorizontal && other->start.row >= start.row
            && other->start.row <= end.row)
         {
            if (other->start.row == start.row && end.row - start.row > 3)
            {
               sink->start.row = start.row - 1;
            }
            else if (other->start.row == end.row && end.row - start.row > 3)
            {
               sink->end.row = end.row - 1;
            }
            if (other->start.col == end.col && other->length > 3)
            {
               ++other->start.col;
               --other->length;
            }
            else if (other->end.col == end.col && other->length > 3)
            {
               --other->end.col;
               --other->length;
            }
         }
         n = n->next;
      }
      sink->length = end.row - start.row + 1;
   }
   sortList(s->sinks, cmpSink);
   listAddSorted(s->sinks, sink, cmpSink);
}

/*
 * Adjusts the known information about the opponent's board and
 * plans the next shot.
 *
 * @param shooter The shooter containing the current data on the opponent's
 * board
 * @param result The result of the last shot.  Either MISS, HIT, or SINK
 */
void processResult(Shooter* shooter, int result)
{
   shooter->board[shooter->shot.row][shooter->shot.col] = result;
   switch (result)
   {
      case MISS:
         processMiss(shooter);
      return;
      case HIT:
         processHit(shooter);
      return;
      case SINK:
         addSink(shooter);
         free(listDelete(shooter->targets, 0));
         if (!shooter->targets->size)
            shooter->state = SCATTER;
         else
         {
            if (shooter->state == TARG_L_H)
               shooter->state = TARG_R_H;
            else if (shooter->state == TARG_U_V)
               shooter->state = TARG_D_V;
            processHit(shooter);
         }
      return;
   }
}

/*
 * Resets a shooter back to it's original state.
 *
 * @param shooter The shooter to reset
 */
void clearShooter(Shooter* shooter)
{
   memset(shooter->board, OPEN_WATER, SIZE*SIZE);
   shooter->state = SCATTER;
   deleteList(shooter->targets);
   shooter->targets = newList();
   deleteList(shooter->sinks);
   shooter->sinks = newList();
}

/*
 * Frees the memory of the given shooter.
 *
 * @param shooter The shooter to free
 */
void deleteShooter(Shooter* shooter)
{
   if (shooter)
   {
      deleteList(shooter->targets);
      deleteList(shooter->sinks);
      free(shooter);
   }
}
