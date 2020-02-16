#
# Makefile for building game from source
#

SOURCE= src/main.cc src/utility.cc src/common.cc src/board.cc src/input.cc src/tetronimo1.cc src/tetronimo2.cc

SOURCE += src/tetronimo3.cc src/tetronimo4.cc src/tetronimo5.cc src/tetronimo6.cc src/tetronimo7.cc src/hard_drop.cc

CC= g++

EXECUTABLE= TetrisFriends

LDFLAGS = -lglfw -lGLU -lGL -lm

OBJECT= $(SOURCE:.cpp=.o)

all: $(OBJECT)
	$(CC) $(SOURCE) $(LDFLAGS) -o $(EXECUTABLE)

$(OBJECT):
	$(CC) -c -o $@ $(@:.o=.cpp)

clean:
	rm -f $(EXECUTABLE) *.o
