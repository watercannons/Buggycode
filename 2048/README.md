# Build Instructions
### To make and run with GHS tools

`sudo apt-get install libncurses5-dev libncursesw5-dev`

`make`

`./2048 or multi 2048`

### To make and run with gdb

`sudo apt-get install libncurses5-dev libncursesw5-dev`

Update Makefile to this:
```
CFLAGS?= -g
LDLIBS= -lncurses
```

`make`

`./2048 or gdb 2048`

# Bug Hunt
At one point, this program was a fully functional game of 2048. A series of bugs have been introduced in order to challenge the users critical thinking skills and debugging knowledge. These introduced bugs will require changes only to existing lines of code. There is no need to add or remove any full lines of code. This program uses the ncurses library to display game information to the terminal. You do not need an in-depth understanding of this library to be able to solve each of these bugs. It is recommended that you solve the problems in the order listed, but it is not completely necessary. 

### Bugs
1. The game stalls and does not react to any keyboard controls. You can only exit the game by using ctrl+c.
2. The game crashes after a few game movements.
3. Restarting the game (r) occasionally causes you to start with a score of 1 or 2 when you should start with 0. Sometimes a tile with a value of 8 or 16 spawns when it shouldn't. There might be some other undefined behavior in the game but these are the primary issues you should focus on.
4. There appears to be an issue with the way the game is saved or loaded. When you quit the game and reopen, the autosaved score is incorrect. You have to quit and run the game two times to get the bug to reproduce. 
5. Restarting (r) the game after playing for a bit seems to cause the score for the next game to be incorrect. Quitting (q) the game and rerunning it appears to "fix" the broken score.

### Helpful Links
- Functioning game: https://gabrielecirulli.github.io/2048/
- Official Game Rules: https://en.wikipedia.org/wiki/2048_(video_game)
