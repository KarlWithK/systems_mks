.POSIX:
.PHONY: run clean
CC= gcc
OBJECTS= main.o euler.o
LDLIBS= -lm

euler: $(OBJECTS)
	$(CC) -o euler $(OBJECTS) $(LDLIBS)

main.o: main.c euler.h
	$(CC) -c main.c

euler.o: euler.c euler.h
	$(CC) -c euler.c

run: euler 
	./euler

clean:
	rm *.o
