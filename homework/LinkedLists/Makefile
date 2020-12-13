CC = g++
exe_file = test

$(exe_file): Node.o Linked_List.o driver.o 
	$(CC) Node.o Linked_List.o driver.o -g -o $(exe_file)

driver.o: driver.cpp
	$(CC) -std=c++11 -c -g driver.cpp

Linked_List.o: Linked_List.cpp
	$(CC) -std=c++11 -c -g Linked_List.cpp

Node.o: Node.cpp
	$(CC) -std=c++11 -c -g Node.cpp

clean:
	rm -f *.out *.o $(exe_file)