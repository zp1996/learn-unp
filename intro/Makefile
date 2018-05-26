include ../Make.defines

PROGS =	3-4 3-7

all: ${PROGS}
	for prog in ${PROGS}; \
	do \
		make "$$prog"; \
	done
3-4: 3-4.o
		${CC} ${CFLAGS} -o $@ 3-4.o ${LIBS}
3-7: 3-7.o
		${CC} ${CFLAGS} -o $@ 3-7.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
