CXX=clang++
# CXX=g++

all:
	$(MAKE) clean
	$(MAKE) test1

run: Main.o
	${CXX} Main.o -o triangulation

test1: Main.o
	${CXX} Main.o -o triangulation
	./triangulation < Input/001_boxPoints.txt > triangle.txt

test2: Main.o
	${CXX} Main.o -o triangulation
	./triangulation < Input/002_boxPermute.txt > triangle.txt

test3: Main.o
	${CXX} Main.o -o triangulation
	./triangulation < Input/003_ellipse.txt > triangle.txt

test4: Main.o
	${CXX} Main.o -o triangulation
	./triangulation < Input/004_ellipseHD.txt > triangle.txt

test5: Main.o
	${CXX} Main.o -o triangulation
	./triangulation < Input/005_ellipseHDRotated.txt > triangle.txt

test6: Main.o
	${CXX} Main.o -o triangulation
	./triangulation < Input/006_ellipseUneven.txt > triangle.txt

test7: Main.o
	${CXX} Main.o -o triangulation
	./triangulation < Input/007_ellipseUneven.txt > triangle.txt

test8: Main.o
	${CXX} Main.o -o triangulation
	./triangulation < Input/008_ellipseUnevenHD.txt > triangle.txt

test9: Main.o
	${CXX} Main.o -o triangulation
	./triangulation < Input/009_ellipseUnevenHD.txt > triangle.txt

clean:
	/bin/rm -f *.o triangulation

Main.o: Main.cpp
	${CXX} -c Main.cpp