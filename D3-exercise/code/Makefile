CC=gcc
CFLAGS=-I.
DEPS=$(wildcard *.h)
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
TARGET=myexec


all: info $(TARGET)
					$(info You are ready to execute!!)

.PHONY: info

info:
	$(info --------------------------- deps)
	$(info $(DEPS))
	$(info ------------------------ srcs)
	$(info $(SRCS))
	$(info --------------------------- OBJS)
	$(info $(OBJS))

%.o: %.c $(DEPS)
	echo "$<" # frist element of r.h.s
	echo "$^" # all r.h.s.
	echo "$@" # target name (l.h.s.)
	$(CC) -c $< $(CFLAGS) -o $@


$(TARGET): $(OBJS)
	@echo "$^"
	$(CC) -o $@ $(OBJS)


clean:
	$(info ********** cleaning up *********)
	@rm -f *~ *.o $(TARGET) > /dev/null 2>&1


.PHONY: clean
# try to modify a .c file and recompile the library
