CXX = g++
CC = g++

all:	01

01: 01.o split.o Rotation.o
01.o:	01.cpp Rotation.o
Rotation.o:	Rotation.cpp Rotation.h split.o
split.o:	split.cc split.h


clean:
	rm -f *.o *.exe core 01 Rotation split
