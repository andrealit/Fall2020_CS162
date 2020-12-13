CC = g++
exe_file = test

$(exe_file): Sort.o driver.o 
	$(CC) Sort.o driver.o -g -o $(exe_file)

driver.o: driver.cpp
	$(CC) -std=c++11 -c -g driver.cpp

Sort.o: Sort.cpp
	$(CC) -std=c++11 -c -g Sort.cpp

clean:
	rm -f *.out *.o $(exe_file)