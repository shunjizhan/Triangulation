CXX=clang++
# CXX=g++

all:
	$(MAKE) clean
	$(MAKE) test1

run: Main.o
	${CXX} Main.o -o triangulation

test1: Main.o
	${CXX} Main.o -o triangulation
	./triangulation < Input/001_boxPoints.txt > out

clean:
	/bin/rm -f *.o triangulation

Main.o: Main.cpp
	${CXX} -c Main.cpp