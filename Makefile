all: main

main: main.cpp card.o 
	g++ -o main main.cpp card.o

card.o: card.cpp
	g++ -c card.cpp


