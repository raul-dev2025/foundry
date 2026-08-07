LTP_SRC ?= /home/builder/Repos/ltp

CFLAGS += -Wall -I../include -I$(LTP_SRC)/include -I$(LTP_SRC)/include/old
LDFLAGS += -L$(LTP_SRC)/lib
LDLIBS += -lltp

.PHONY: all clean

all: mmap01 direct_io01

mmap01: mmap01.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< $(LDLIBS) -o $@

direct_io01: direct_io_test.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< $(LDLIBS) -o $@

clean:
	rm -f mmap01 direct_io01 *.o