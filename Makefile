CFLAGS  = -Wall -std=c11 -g
LIBS = -lm

.PHONY: clean 

all : arrays

clean :
	rm -f *.o  *~ arrays test

test : arrays.o test.o
	gcc $(CFLAGS) -o test arrays.o test.o $(LIBS)

arrays: ui.o arrays.o main.o
	gcc $(CFLAGS) -o arrays ui.o arrays.o main.o $(LIBS)

test.o : test.c arrays.h
	gcc $(CFLAGS) -c test.c

main.o : ui.o arrays.o main.c arrays.h ui.h
	gcc $(CFLAGS) -c main.c

ui.o : arrays.o ui.c ui.h arrays.h
	gcc $(CFLAGS) -c ui.c

arrays.o : arrays.c arrays.h
	gcc $(CFLAGS) -c arrays.c
