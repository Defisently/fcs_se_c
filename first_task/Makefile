CC = gcc
CFLAGS = -g

all: main tests

main: main.o calc_operations.o
	$(CC) $(CFLAGS) -o main main.o calc_operations.o

tests: tests.o calc_operations.o
	$(CC) $(CFLAGS) -o tests tests.o calc_operations.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main tests