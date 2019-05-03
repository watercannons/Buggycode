CC			= g++
LD			= g++
CCFLAGS 	= -g -std=c++11
LDFLAGS 	= -lm -lpthread
TARGET		= hashTest
SOURCES		= $(wildcard *.cpp)
OBJECTS		= $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $< $(CCFLAGS)

clean:
	rm -f $(OBJECTS) $(TARGET)
