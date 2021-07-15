.POSIX:
.PHONY: run clean
CC= gcc
CFLAGS= -g -Wall -Wextra -Wpedantic -Wuninitialized -Wundef -Wcast-align -Wstrict-overflow=2 -Wwrite-strings -Wno-format-nonliteral
BINARY=shux
OBJECTS= main.o shux.o
LFLAGS= -fsanitize=address

run: $(BINARY)
	./$(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $(BINARY) $(OBJECTS) $(LFLAGS)

main.o: main.c shux.h
	$(CC) $(CFLAGS) -c $<

shux.o: shux.c shux.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o $(BINARY)
