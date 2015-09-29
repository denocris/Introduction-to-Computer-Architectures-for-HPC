CC=gcc
CFLAGS=-O0 -Wall
LFLAGS=-lrt

SRC= ex01.c ex02.c
EXE= $(SRC:%.c=%.x)

all: $(EXE)

clean:
	rm -f *.x *.o *~

.SUFFIX:
.SUFFIX: .x .c

%.x: %.c
	$(CC) -o $@ $(CFLAGS) $< $(LFLAGS)

