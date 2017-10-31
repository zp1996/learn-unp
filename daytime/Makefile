include ../Make.defines

PROGS =	1-2

all: ${PROGS}
	for prog in ${PROGS}; \
	do \
		make "$$prog"; \
	done

1-2: 1-2.o
		${CC} ${CFLAGS} -o $@ 1-2.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
