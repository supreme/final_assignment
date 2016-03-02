all: game

game: game.o organism.o ant.o doodlebug.o field.o
	g++ -g game.o organism.o ant.o doodlebug.o field.o -o game

game.o: game.cpp organism.h ant.h doodlebug.h field.h position.h
	g++ -g -c game.cpp

organism.o: organism.cpp organism.h position.h
	g++ -g -c organism.cpp

ant.o: ant.cpp ant.h organism.h position.h
	g++ -g -c ant.cpp

doodlebug.o: doodlebug.cpp doodlebug.h organism.h position.h
	g++ -g -c doodlebug.cpp

field.o: field.cpp field.h organism.h position.h
	g++ -g -c field.cpp

clean:
	rm -f *.o game

docs:
	doxygen
	chmod a+r,a-x html/*
	cp -r -p html/* ~/public_html/cs2303assig6
