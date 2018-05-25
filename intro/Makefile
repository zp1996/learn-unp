include ../Make.defines

PROGS =	3-4

all: ${PROGS}
	for prog in ${PROGS}; \
	do \
		make "$$prog"; \
	done
3-4: 3-4.o
		${CC} ${CFLAGS} -o $@ 3-4.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
