CC       ?= gcc
CCFLAGS  ?= -std=c89 -pedantic -Wall -Werror
LDFLAGS  ?= -lm
TARGETS   = server client
SOURCES   = $(filter-out tester.c, $(wildcard *.c))
INCLUDES  = $(wildcard *.h)
OBJECTS   = $(SOURCES:.c=.o)

all: $(TARGETS)

server: server.o
	$(CC) -o $@ $^ $(LDFLAGS)

client: client.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $^ $(CCFLAGS)

clean:
	rm -f $(TARGETS) $(SOURCES:.c=.dbo) $(OBJECTS) $(SOURCES:.c=.dla) $(SOURCES:.c=.dnm)
