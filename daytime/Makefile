include ../Make.defines

PROGS =	1-2 1-5

all: ${PROGS}
	for prog in ${PROGS}; \
	do \
		make "$$prog"; \
	done

1-2: 1-2.o
	${CC} ${CFLAGS} -o $@ 1-2.o ${LIBS}
1-5: 1-5.o
	${CC} ${CFLAGS} -o $@ 1-5.o ${LIBS}

clean:
	rm -f ${PROGS} ${CLEANFILES}
