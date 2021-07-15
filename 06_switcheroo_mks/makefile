.POSIX:
.PHONY: run clean
CC= gcc
OBJECTS= main.o
LDLIBS= -lm

main: $(OBJECTS)
	$(CC) -o main $(OBJECTS) $(LDLIBS)

main.o: main.c
	$(CC) -c main.c

run: main 
	./main

clean:
	rm *.o
