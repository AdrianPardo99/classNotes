PROJ=proc1
DSTPATH=/usr/local/bin
CLFLAGS=-Wall
COBJ=-c
CC=gcc
SRCC=$(wildcard *.c)
OBJS=$(SRCC:.c=.o)

all: ${PROJ}

%.o:	%.c
	${CC} ${COBJ} $< ${CFLAGS}

${PROJ}: ${OBJS}
	${CC} $^ -o $@

.PHONY: clean

clean:
	rm -f *.o ${PROJ}
