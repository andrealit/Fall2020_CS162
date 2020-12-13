CC = g++
exe_file = test

$(exe_file): emp_hours.o pizza.o prog.o
	$(CC) emp_hours.o pizza.o prog.o -o $(exe_file)

prog.o: prog.cpp
	$(CC) -std=c++11 -c prog.cpp

emp_hours.o: emp_hours.cpp
	$(CC) -std=c++11 -c emp_hours.cpp

pizza.o: pizza.cpp
	$(CC) -std=c++11 -c pizza.cpp

clean:
	rm -f *.out *.o $(exe_file)