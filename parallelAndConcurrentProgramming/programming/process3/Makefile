PROJ=proc3
DSTPATH=/usr/local/bin
CFLAGS=-Wall
COBJ=-c
LINKF=-lm
CC=gcc
SRCC=$(wildcard *.c)
OBJS=$(SRCC:.c=.o)
all: ${PROJ}

%.o:	%.c
	${CC} ${COBJ} $< ${CFLAGS}

${PROJ}: ${OBJS}
	${CC} $^ -o $@ ${LINKF}

.PHONY: clean

clean:
	rm -f *.o ${PROJ} *.gch
