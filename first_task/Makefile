CC = gcc
CFLAGS = -g

all: main tests

main: main.o io.o calc_operations.o
	$(CC) $(CFLAGS) -o main main.o io.o calc_operations.o

tests: tests.o calc_operations.o
	$(CC) $(CFLAGS) -o tests tests.o calc_operations.o

main.o: main.c io.h calc_operations.h
io.o: io.c io.h calc_operations.h
calc_operations.o: calc_operations.c calc_operations.h
tests.o: tests.c calc_operations.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main tests