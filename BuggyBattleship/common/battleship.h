/*
 * PROVIDED FILE - !!! DO NOT MODIFY !!!
 *
 * However, you must use the #define macros below and NOT hardcode the
 * associated values in your code. I may change some of the numbers when
 * testing and your code to make sure you have done so used the #defines
 * correctly! NOTE: I will not change the number of ships but you should
 * still use that constant for readability!
 */
#ifndef BATTLESHIP_H
#define BATTLESHIP_H

/* The Battleship board size. The board is a SIZExSIZE 2-dimensional char array. 
 */
#define SIZE 10

/* The maximum number of shots it should take to sink every ship */
#define MAX_SHOTS SIZE*SIZE

/* The value each cell of the board contains when it is empty (no ship).
 */
#define OPEN_WATER 0

/* Number of ships
 */
#define NUMBER_OF_SHIPS 5

/* Ship types - The values to put on the board when hiding the ships
 */
#define AIRCRAFT_CARRIER 1
#define BATTLESHIP 2
#define DESTROYER 3
#define SUBMARINE 4
#define PATROL_BOAT 5

/* Ship sizes - The number of position each ship takes on the board
 */
#define SIZE_AIRCRAFT_CARRIER 5
#define SIZE_BATTLESHIP 4
#define SIZE_DESTROYER 3
#define SIZE_SUBMARINE 3
#define SIZE_PATROL_BOAT 2

/* Possible shot outcomes - passed as an int.
 */
#define UNKNOWN 0
#define MISS 1 
#define HIT  2 
#define SINK 3 

/* Battleship game host-to-player message types - passed as an int.
 */
#define NEW_GAME 100 
#define SHOT_REQUEST 101
#define SHOT_RESULT 103
#define OPPONENTS_SHOT 104
#define MATCH_OVER 105

/* Structure representing the coordinates of a shot - this is the structure
 * the player will send to the game host.
 */
typedef struct
{
   unsigned short row; /* The row index of a shot */
   unsigned short col; /* The column index of a shot */
} Shot;

#endif
