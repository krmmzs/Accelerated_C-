CXX = g++
CC = g++

all:	01 02 03 04 05 06 07

Student_info.o:	Student_info.cc Student_info.h

grade.o:	grade.cc grade.h median.h Student_info.h

# main3.o:	main3.cc grade.h median.h Student_info.h

median.o:	median.cc median.h

06:		06.o grade.o median.o Student_info.o

clobber:
	rm -f *.o *.exe core 01 02 03 04 05 06 07
