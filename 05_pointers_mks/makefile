.POSIX:
.PHONY: run clean
CC= gcc
OBJECTS= main.o

main: $(OBJECTS)
	$(CC) -o main $(OBJECTS)

main.o: main.c
	$(CC) -c main.c

run: main 
	./main

clean:
	rm *.o
