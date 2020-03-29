CFLAGS = -c -Wall
CC = gcc
LIBS = -lm

all: main

main: main.o fields.o jrb.o jval.o
	${CC} main.o fields.o jrb.o jval.o -o main

main.o: main.c
	${CC} ${CFLAGS} main.c

fields.o: fields.c
	${CC} ${CFLAGS} fields.c

jrb.o: jrb.c
	${CC} ${CFLAGS} jrb.c

jval.o: jval.c
	${CC} ${CFLAGS} jval.c

clean:
	rm -f *.o *~
