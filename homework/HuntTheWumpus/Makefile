CC = g++
exe_file = test

$(exe_file): Event.o Room.o Pit.o Wumpus.o Gold.o Bats.o Game.o main.o
	$(CC) Event.o Room.o Pit.o Wumpus.o Gold.o Bats.o Game.o main.o -o $(exe_file) -lncurses

main.o: main.cpp
	$(CC) -std=c++11 -c main.cpp

Game.o: Game.cpp
	$(CC) -std=c++11 -c Game.cpp

Bats.o: Bats.cpp
	$(CC) -std=c++11 -c Bats.cpp

Gold.o: Gold.cpp
	$(CC) -std=c++11 -c Gold.cpp

Wumpus.o: Wumpus.cpp
	$(CC) -std=c++11 -c Wumpus.cpp

Pit.o: Pit.cpp
	$(CC) -std=c++11 -c Pit.cpp

Room.o: Room.cpp
	$(CC) -std=c++11 -c Room.cpp

Event.o: Event.cpp
	$(CC) -std=c++11 -c Event.cpp

clean:
	rm -f *.out *.o $(exe_file)