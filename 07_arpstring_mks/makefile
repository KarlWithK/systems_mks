.POSIX:
.PHONY: run clean
CC= gcc
OBJECTS= main.o funs.c

main: $(OBJECTS)
	$(CC) -o main $(OBJECTS)

main.o: main.c funs.h
	$(CC) -c main.c

funs.o: funs.c funs.h
	$(CC) -c funs.c

run: main
	./main

clean:
	rm *.o
	rm main
