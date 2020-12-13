CC = g++
exe_file = test

$(exe_file): catalog.o run_wizard.o
	$(CC) catalog.o run_wizard.o -o $(exe_file)

catalog.o: catalog.cpp
	$(CC) -std=c++11 -c catalog.cpp

run_wizard.o: run_wizard.cpp
	$(CC) -std=c++11 -c run_wizard.cpp

clean:
	rm -f *.out *.o $(exe_file)