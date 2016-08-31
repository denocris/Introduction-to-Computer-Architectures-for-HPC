# constants
CC=gcc
CFLAGS=-O0 -Wall
LDFLAGS=-lm

SRC= ex01.c ex02.c
EXE= $(SRC:%.c=%.x)

# targets

# make with no arguments executes the first rule
all: $(EXE)

clean:
	rm -f *.x *.o *~

# delete default suffixes
.SUFFIX:

# define our suffix list
.SUFFIX: .x .c

# each .x depends on upon the .c version of the file
%.x: %.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS)

