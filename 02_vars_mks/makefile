OBJECTS= main.o
CC= gcc

main: $(OBJECTS)
	$(CC) -o main $(OBJECTS)

main.o: main.c
	$(CC) -c main.c

run: main
	./main

clean:
	rm *.o
