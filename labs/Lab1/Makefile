CC = g++
exe_file = calculated
$(exe_file): mult_div_values.o run_math.o
	$(CC) mult_div_values.o run_math.o -o $(exe_file)
mult_div_values.o: mult_div_values.cpp
	$(CC) -c mult_div_values.cpp
run_math.o: run_math.cpp
	$(CC) -c run_math.cpp
clean:
	rm -f *.out *.o $(exe_file)