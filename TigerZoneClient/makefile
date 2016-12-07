#this target will compile all files
all: TigerZone

TigerZone: board.o card.o deck.o game.o player.o jungle.o edge.o input.o output.o trail.o lake.o main.o
	g++ board.o card.o deck.o game.o player.o jungle.o edge.o input.o output.o trail.o lake.o main.o -o tiger.out

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

board.o: board.cpp
	g++ -std=c++11 -c board.cpp

card.o: card.cpp
	g++ -std=c++11 -c card.cpp

game.o: game.cpp
	g++ -std=c++11 -c game.cpp

deck.o: deck.cpp
	g++ -std=c++11 -c deck.cpp

player.o: player.cpp
	g++ -std=c++11 -c player.cpp

jungle.o: jungle.cpp
	g++ -std=c++11 -c jungle.cpp

edge.o: edge.cpp
	g++ -std=c++11 -c edge.cpp

input.o: input.cpp
	g++ -std=c++11 -c input.cpp

output.o: output.cpp
	g++ -std=c++11 -c output.cpp

trail.o: trail.cpp
	g++ -std=c++11 -c trail.cpp

lake.o: lake.cpp
	g++ -std=c++11 -c lake.cpp

clean:
	rm -rf *o tiger.out
