#
# Makefile for building game from source
#

SOURCE= src/main.cc src/utility.cc src/common.cc src/board.cc src/input.cc src/tetronimos/tetronimo1.cc src/tetronimos/tetronimo2.cc
SOURCE += src/tetronimos/tetronimo3.cc src/tetronimos/tetronimo4.cc src/tetronimos/tetronimo5.cc src/tetronimos/tetronimo6.cc
SOURCE += src/tetronimos/tetronimo7.cc src/hard_drop.cc

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
