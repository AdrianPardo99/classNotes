PROJ=muestreo
ARCHF=archivos
PROCF=procesamiento
DSTPATH=/usr/local/bin
CFLAGS=-Wall
COBJ=-c
LINKF=-lm
CC=gcc
all: ${PROJ}

${PROJ}.o:	${PROJ}.c
	${CC} ${COBJ} ${PROJ}.c ${CFLAGS}

${PROCF}.o: ${PROCF}.c
	${CC} ${COBJ} ${PROCF}.c ${CFLAGS}

${ARCHF}.o: ${ARCHF}.c
	${CC} ${COBJ} ${ARCHF}.c ${CFLAGS}

${PROJ}: ${PROJ}.o ${PROCF}.o ${ARCHF}.o
	${CC} ${PROJ}.o ${PROCF}.o ${ARCHF}.o -o ${PROJ} ${LINKF}

.PHONY: clean

install: all
	if [ ! -d ${DSTPATH} ]; then\
		sudo mkdir ${DSTPATH}; \
	fi
	sudo cp ${PROJ} ${DSTPATH}

uninstall:
	sudo rm ${DSTPATH}/${PROJ}

clean:
	rm -f *.o ${PROJ}
