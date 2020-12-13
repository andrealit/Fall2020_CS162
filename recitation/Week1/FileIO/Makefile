CC = g++ -std=c++11
exe_file = book_app

# Handle debug case
DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS := -g -Wall
else
	CFLAGS := -DNDEBUG -O3
endif

$(exe_file): book.o prog_fileio.o
	$(CC) book.o prog_fileio.o -o $(exe_file) $(CFLAGS)
book.o: book.cpp
	$(CC) -c book.cpp $(CFLAGS)
prog_fileio.o: prog_fileio.cpp
	$(CC) -c prog_fileio.cpp $(CFLAGS)

clean:
	rm -f *.out *.o $(exe_file)

.PHONY: clean
