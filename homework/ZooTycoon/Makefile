CC = g++ -g
exe_file = test

$(exe_file): Animal.o BlackBear.o SeaLion.o Tiger.o Zoo.o zootycoon.o
	$(CC) Animal.o BlackBear.o SeaLion.o Tiger.o Zoo.o zootycoon.o -o $(exe_file)

zootycoon.o: zootycoon.cpp
	$(CC) -std=c++11 -c zootycoon.cpp

Zoo.o: Zoo.cpp
	$(CC) -std=c++11 -c Zoo.cpp

Tiger.o: Tiger.cpp
	$(CC) -std=c++11 -c Tiger.cpp

SeaLion.o: SeaLion.cpp
	$(CC) -std=c++11 -c SeaLion.cpp

BlackBear.o: BlackBear.cpp
	$(CC) -std=c++11 -c BlackBear.cpp

Animal.o: Animal.cpp
	$(CC) -std=c++11 -c Animal.cpp

clean:
	rm -f *.out *.o $(exe_file)