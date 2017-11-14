#Dwight Whitlock

CC = g++
DEBUG = -g -O0 -pedantic-errors
CFLAGS = -Wall -std=c++14 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) -o
EXECUTABLE = TreeDr

all: $(EXECUTABLE)

$(EXECUTABLE): TreeType.o QueType.o TreeDr.o
	$(CC) $(LFLAGS) $(EXECUTABLE) TreeType.o QueType.o TreeDr.o

$(TreeType.o): src/TreeType.cpp
	$(CC) $(CFLAGS) src/TreeType.cpp

$(QueType.o): src/QueType.cpp
	$(CC) $(CFLAGS) src/QueType.cpp

$(TreeDr.o): src/TreeDr.cpp
	$(CC) $(CFLAGS) src/TreeDr.cpp

clean:
	rm -rf *.o
	rm -rf TreeDr
	rm -rf output.txt