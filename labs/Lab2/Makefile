CC = g++
exe_file = lab2out

$(exe_file): student_db.o driver.o
	$(CC) student_db.o driver.o -o $(exe_file)

student_db.o: student_db.cpp
	$(CC) -std=c++11 -c student_db.cpp

driver.o: driver.cpp
	$(CC) -std=c++11 -c driver.cpp

clean:
	rm -f *.out *.o $(exe_file)