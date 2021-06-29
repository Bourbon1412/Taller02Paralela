CXX = g++
CXXFLAGS = -std=c++11 -g3 -Wall 
MKDIR = mkdir -p

LIBS = -lm 

clean:
	rm -fr *.o a.out core programa dist build

directorios:
	$(MKDIR) build bin

funciones.o: directorios funciones.cpp
	$(CXX) $(CXXFLAGS) -c funciones.cpp -o build/funciones.o

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

all: clean main.o funciones.o
	$(CXX) $(CXXFLAGS) -o bin/programa build/main.o build/funciones.o $(LIBS)
	rm -fr build

.DEFAULT_GOAL := all
