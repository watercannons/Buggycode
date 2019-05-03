CC       ?= gcc
CCFLAGS  ?= -std=c89 -pedantic -Wall -Werror
LDFLAGS  ?= -lm
TARGET    = host
SOURCES   = $(wildcard *.c)
INCLUDES  = $(wildcard *.h)
OBJECTS   = $(SOURCES:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

%.o: %.c
	$(CC) -c $^ $(CCFLAGS)

clean:
	rm -f $(TARGET) $(OBJECTS) $(SOURCES:.c=.dbo) host.dla host.dnm
