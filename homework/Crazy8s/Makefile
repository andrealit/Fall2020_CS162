CC = g++
exe_file = test

$(exe_file): Game.o Player.o Deck.o Hand.o Card.o crazyeights.o
	$(CC) Game.o Player.o Deck.o Hand.o Card.o crazyeights.o -o $(exe_file)

crazyeights.o: crazyeights.cpp
	$(CC) -std=c++11 -c crazyeights.cpp

Card.o: Card.cpp
	$(CC) -std=c++11 -c Card.cpp

Hand.o: Hand.cpp
	$(CC) -std=c++11 -c Hand.cpp

Deck.o: Deck.cpp
	$(CC) -std=c++11 -c Deck.cpp

Player.o: Player.cpp
	$(CC) -std=c++11 -c Player.cpp

Game.o: Game.cpp
	$(CC) -std=c++11 -c Game.cpp

clean:
	rm -f *.out *.o $(exe_file)