.POSIX:
.PHONY: all clean
BINARY=main
CC= gcc
CFLAGS= -g -Wall -Wextra -Wpedantic -Wuninitialized -Wundef -Wcast-align -Wstrict-overflow=2 -Wwrite-strings -Wno-format-nonliteral
# CFLAGS= -Wall -Wpedantic -Werror -Wextra
OBJECTS= main.o mystring.o

main: $(OBJECTS)
	$(CC) -o $(BINARY) $(OBJECTS)

main.o: main.c mystring.h
	$(CC) $(CFLAGS) -c main.c

mystring.o: mystring.c mystring.h
	$(CC) $(CFLAGS) -c mystring.c

all: $(BINARY) 
	./$(BINARY)

clean:
	rm *.o
	rm $(BINARY)
