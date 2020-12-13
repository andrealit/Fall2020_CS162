CC = g++
exe_file = test

$(exe_file): Card.o Deck.o Hand.o Player.o Game.o crazyeights.o
	$(CC) Card.o Deck.o Hand.cpp Player.o Game.o crazyeights.o -o $(exe_file)

crazyeights.o: crazyeights.cpp
	$(CC) -std=c++11 -c crazyeights.cpp

Game.o: Game.cpp
	$(CC) -std=c++11 -c Game.cpp

Player.o: Player.cpp
	$(CC) -std=c++11 -c Player.cpp

Hand.o: Hand.cpp
	$(CC) -std=c++11 -c Hand.cpp

Deck.o: Deck.cpp
	$(CC) -std=c++11 -c Deck.cpp

Card.o: Card.cpp
	$(CC) -std=c++11 -c Card.cpp

clean:
	rm -f *.out *.o $(exe_file)