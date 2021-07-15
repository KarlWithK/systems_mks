.POSIX:
.PHONY: run clean
CC= gcc
CFLAGS= -g -Wall -Wextra -Wpedantic -Wuninitialized -Wundef -Wcast-align -Wstrict-overflow=2 -Wwrite-strings -Wno-format-nonliteral
BINARY=main
OBJECTS= main.o fighter.o
LFLAGS= -fsanitize=address

$(BINARY): $(OBJECTS)
	$(CC) -o $(BINARY) $(OBJECTS) $(LFLAGS)

main.o: main.c fighter.h
	$(CC) -c $< $(CFLAGS)

fighter.o: fighter.c fighter.h
	$(CC) -c $< $(CFLAGS)

run: $(BINARY)
	./$(BINARY)

clean:
	rm *.o $(BINARY)
