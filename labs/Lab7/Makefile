CC = g++
exe_file = test

$(exe_file): Shape.o Rectangle.o Circle.o Square.o application.o
	$(CC) Shape.o Rectangle.o Circle.o Square.o application.o -o $(exe_file)

application.o: application.cpp
	$(CC) -std=c++11 -c application.cpp

Square.o: Square.cpp
	$(CC) -std=c++11 -c Square.cpp

Circle.o: Circle.cpp
	$(CC) -std=c++11 -c Circle.cpp

Rectangle.o: Rectangle.cpp
	$(CC) -std=c++11 -c Rectangle.cpp

Shape.o: Shape.cpp
	$(CC) -std=c++11 -c Shape.cpp

clean:
	rm -f *.out *.o $(exe_file)