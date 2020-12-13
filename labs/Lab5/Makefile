CC = g++
exe_file = test

$(exe_file): Car.o driver.o
	$(CC) Car.o driver.o -o $(exe_file)

driver.o: driver.cpp
	$(CC) -std=c++11 -c driver.cpp

Car.o: Car.cpp
	$(CC) -std=c++11 -c Car.cpp

clean:
	rm -f *.out *.o $(exe_file)