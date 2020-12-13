CC = g++
exe_file = lab3out

$(exe_file): card.o deck.o driver.o
	$(CC) card.o deck.o driver.o -o $(exe_file)

driver.o: driver.cpp
	$(CC) -std=c++11 -c driver.cpp

card.o: card.cpp
	$(CC) -std=c++11 -c card.cpp

deck.o: deck.cpp
	$(CC) -std=c++11 -c deck.cpp

clean:
	rm -f *.out *.o $(exe_file)