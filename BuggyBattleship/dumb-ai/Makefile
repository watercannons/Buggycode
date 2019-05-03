CC       ?= gcc
CCFLAGS  ?= -std=c89 -pedantic -Wall -Werror
LDFLAGS  ?= -lm
TARGET    = player
SOURCES   = $(filter-out tester.c, $(wildcard *.c))
INCLUDES  = $(wildcard *.h)
OBJECTS   = $(SOURCES:.c=.o)

all:$(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

%.o: %.c
	$(CC) -c $^ $(CCFLAGS)

clean:
	rm -f $(TARGET) $(SOURCES:.c=.dbo) $(OBJECTS) player.dla player.dnm
