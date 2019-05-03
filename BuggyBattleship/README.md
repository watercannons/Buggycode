# Battleship
## Important
#### You may use man pages, Google, or any other source of information for this assignment.

#### There are tips for how to query certain information at the bottom of this README.

## How to build
To build a component, run `make` in the directory of that component.

To build all the components, run `make` in the root directory.

Each component's output binary will be in the component directory.

## Bugs
### Bug 1 - Only help message (Ref. 99b18c0)
The program only ever gives me the help message.  I know I'm using it correctly
but it won't run!

### Bug 2 - Game won't start (Ref. 129c762)
Nothing happens after I start the game!
I'm not getting help messages any more but nothing happens after that.

### Bug 3 - Program doesn't finish (Ref. b6e53cd)
I can play through all my games, but it just hangs after the last game.

### Bug 4 - Doesn't work if children in same dir (Ref. 400d6c9)
When I have all the programs in the same directroy and I try to run it, it doesn't
work!  Here's the line I'm running: `./host aiplayer humanplayer`

### Bug 5 - Rehitting targets (Ref. eb3f1c1)
For some reason, when I hit a spot repeatedly, sometimes I might sink a ship.
It doesn't always happen, but it usually works towards the beginning of the game and only
when I already scored a hit.

### Example make/runs
Make and run the program with an interactive player:

`~/Battleship $ make
~/Battleship $ host/host ai/player player/player`

Make and run the program with two ai's:

`~/Battleship $ make
~/Battleship $ host/host -d ai/player dumb-ai/player`

Remove binary files/clean working directories:

`~/Battleship $ make clean`

Run with multi:

`~/Battleship $ multi host/host`
Then to set the arguments, use: `Debug->Set Program Arguments`

## How to play
Each game has 3 components: a host and two players (the players may be the same).
The host will launch each of the players as a separate process and use pipes

Each player alternates taking turns until one of the players has sunk each of the
opponent's ships. (If the first player sink all the other's ships first, the second
player will get one more turn to attempt to tie the game.)

A turn proceeds as follows:
1. Host asks active player for a shot.
2. Active replies with a shot.
3. Host informs passive player where active shot.
4. Host tells active player whether it missed, hit or sunk a ship.

## Components
### host
Manages basic information about the game.  Use this to launch the game by providing
two player systems like so:

`host [-g#|-d] <player1> <player2>`

Use `-gN` to run N games.  The default is 3.

Use `-d` to print game details, useful when running two AI's against each other or
to check the host state.

Also note that the host expects each player to take arguments in the following format:

`player <read-fd> <write-fd>`

The host will then use the other two fd's to communicate with the player object.  
Stdin/stdout are not touched and may be used for debug or interactivity.

### player
An interactive player for the game.  Useful for provoking specific behavior and
testing.

### ai
A relatively inteligent ai that will strategically look for ships, althought it can
be a bit predictable.

### dumb-ai
This ai is a moron.  It will shoot every tile in order and always puts it's ships in
the same spot every time.  This should never win against any reasonable ai.

### ip-player
This player serves as a middle-man for running a game over a network.  This is built
from two subcomponents: client and server.

TODO: A the momment, the server print's it's current ip:port like so:

`:::<port>`

In IPv6 `::` represents all zeros, referring to a generic ip address.  The port should
still work, but you'll have to get the ip address seperately for now.  You can do this
with the command `ip addr` on linux.

#### server
The opens a connection for the client.  Once a connection is established, this will simply
pass any data it recieves from either the host or the connected client to the other.  
This should provide a perfectly transparent connection to the host.

#### client
Takes as arguments a host and port number to connect to, as well as a player program to
execute.  It will attempt to connect to the host and port and upon success will launch the
player.

#### Example Usage
Launches an ai against a remote player, and prints game details:
`~/Battleship@host1 $ host/host -d ai/player ip-player/server
Network player listening on :::34532.`

`~/Battleship@host2 $ ip-player/server host1 34532 player/player`

### common
Common files used by most or all executables.

## Helpful Tips
### Reporting Errors
Some horrible programmer never checked any of their error codes.  "It won't be a problem
because it should never happen," they say.  Well now functions will run sometimes right
past the point of error without ever telling you.

If you find a function you think is returning an error, I recommending adding a call to
`perror`.  This function will print a message to stderr describing the current state of the
global errno.  This is useful for seeing when an error happens and giving you a message you
can easily Google.

Note: `perror` will always print something, even if there is no error.  Make sure to check
your return values to see if you need to call `perror` to prevent extra messages.

### Seeing a list of processes
When running multi-processed programs, it's often useful to know what processes are currently
ctive.  You can get this information from a unix terminal with the command:
`ps -U <username>`.

### Bind Multi to children
Use the command `P c` in the multi terminal to tell multi to bind to child processes. 

Note that this will also trigger multi to halt the process and it's child during fork's and
exec's.  This might be unsettling at first as it will display assembly code.  Simply return
out until you reach normal execution.  Also, this will halt both the parent and child so be
sure to resume both.

If this behavior becomes disruptive, you can toggle flags to disable this.  Use `help P`
for more information.

### History with multiprocessing
To use history with a multi-processed program, start the parent.  Stop it before
the desired fork, and type `P c` in the console.  Multi will now attach to fork'ed
children.

### List of file descriptors (fd's) for a process
This program uses lots of fd's to communicate between processes.  Being able to inspect
the file descriptor table may be useful.  Use the command `ls -l /proc/<pid>/fd` to see
details about the fd's for a given process by it's pid.

To get the pid for a program, run the command: `ps -U <username> | grep <executable name>`.