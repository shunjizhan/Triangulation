CXX=clang++
# CXX=g++

all:
	$(MAKE) clean
	$(MAKE) run

run: Main.o
	${CXX} Main.o -o triangulation

test: Main.o
	${CXX} Main.o -o triangulation
	./triangulation < Input/001_boxPoints.txt

clean:
	/bin/rm -f *.o triangulation

Main.o: Main.cpp
	${CXX} -c Main.cpp