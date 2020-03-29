CFLAGS = -c -Wall
CC = gcc
LIBS = -lm

all: main

main: main.o 
	${CC} main.o graph.c jrb.c jval.c dllist.c fields.c -o pr

main.o: main.c
	${CC} ${CFLAGS} main.c

clean:
	rm -f *.o *~ main
