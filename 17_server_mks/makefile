.POSIX:
.PHONY: run clean
CC= gcc
CFLAGS= -g -Wall -Wextra -Wpedantic -Wuninitialized -Wundef -Wcast-align -Wstrict-overflow=2 -Wwrite-strings -Wno-format-nonliteral
OBJECTS= server.o client.o
LFLAGS= -lasan

all: $(OBJECTS)
	$(CC) -o server server.o $(LFLAGS)
	$(CC) -o client client.o $(LFLAGS)

server.o: server.c
	$(CC) $(CFLAGS) -c server.c

client.o: client.c
	$(CC) $(CFLAGS) -c client.c

# run: server client
# 	./server
# 	./client

clean:
	rm *.o server client
