SOURCE= src/main.cc src/utility.cc src/common.cc src/board.cc src/input.cc src/tetronimo1.cc src/tetronimo2.cc src/tetronimo3.cc

CC= g++

EXECUTABLE= FruitTetris

LDFLAGS = -lglfw -lGLU -lGL -lm

OBJECT= $(SOURCE:.cpp=.o)

all: $(OBJECT)
	$(CC) $(SOURCE) $(LDFLAGS) -o $(EXECUTABLE)

$(OBJECT):
	$(CC) -c -o $@ $(@:.o=.cpp)

clean:
	rm -f $(EXECUTABLE) *.o
