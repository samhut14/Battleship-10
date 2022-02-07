Project: main.o Board.o Player.o Game.o Ship.o helper.o
	g++ -std=c++11 -g -Wall main.o Board.o Player.o Game.o Ship.o helper.o -o Project
main.o: main.cpp Board.h Player.h Game.h Ship.h
	g++ -std=c++11 -g -Wall -c main.cpp
Board.o: Board.h Board.cpp
	g++ -std=c++11 -g -Wall -c Board.cpp
Player.o: Player.h Player.cpp
	g++ -std=c++11 -g -Wall -c Player.cpp
Game.o: Game.h Game.cpp
	g++ -std=c++11 -g -Wall -c Game.cpp
Ship.o: Ship.h Ship.cpp
	g++ -std=c++11 -g -Wall -c Ship.cpp
helper.o: helper.h helper.cpp
	g++ -std=c++11 -g -Wall -c helper.cpp
clean:
	rm *.o Project