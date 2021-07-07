#-*-Makefile-*-

CC = g++
CCFLAGS = -std=c++11

srcDir = ./src
includeDir = ./include
buildDir = ./build
distDir = ./dist

base2: $(distDir)/base2

base1: $(distDir)/base1

$(distDir)/base2: $(buildDir)/main.o $(buildDir)/link.o $(buildDir)/acquireLinks.o $(buildDir)/acquireHuristics.o $(buildDir)/node.o $(buildDir)/list.o
	$(CC) $(CCFLAGS) $(buildDir)/main.o $(buildDir)/link.o $(buildDir)/acquireLinks.o $(buildDir)/acquireHuristics.o $(buildDir)/node.o $(buildDir)/list.o -o $(distDir)/base2

$(distDir)/base1: $(buildDir)/main.o $(buildDir)/link.o $(buildDir)/functions.o $(buildDir)/node.o $(buildDir)/list.o
	$(CC) $(CCFLAGS) $(buildDir)/main.o $(buildDir)/link.o $(buildDir)/functions.o $(buildDir)/node.o $(buildDir)/list.o -o $(distDir)/base1

$(buildDir)/main.o: $(srcDir)/main.cpp
	$(CC) $(CCFLAGS) -c $(srcDir)/main.cpp -o $(buildDir)/main.o

$(buildDir)/link.o: $(srcDir)/link.cpp $(includeDir)/link.h
	$(CC) $(CCFLAGS) -c $(srcDir)/link.cpp -o $(buildDir)/link.o

$(buildDir)/functions.o: $(srcDir)/functions.cpp $(includeDir)/functions.h
	$(CC) $(CCFLAGS) -c $(srcDir)/functions.cpp -o $(buildDir)/functions.o

$(buildDir)/acquireLinks.o: $(srcDir)/acquireLinks.cpp $(includeDir)/functions.h
	$(CC) $(CCFLAGS) -c $(srcDir)/acquireLinks.cpp -o $(buildDir)/acquireLinks.o

$(buildDir)/acquireHuristics.o: $(srcDir)/acquireHuristics.cpp $(includeDir)/functions.h
	$(CC) $(CCFLAGS) -c $(srcDir)/acquireHuristics.cpp -o $(buildDir)/acquireHuristics.o	

$(buildDir)/node.o: $(srcDir)/node.cpp $(includeDir)/node.h
	$(CC) $(CCFLAGS) -c $(srcDir)/node.cpp -o $(buildDir)/node.o

$(buildDir)/list.o: $(srcDir)/list.cpp $(includeDir)/list.h
	$(CC) $(CCFLAGS) -c $(srcDir)/list.cpp -o $(buildDir)/list.o