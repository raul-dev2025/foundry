LTP_SRC ?= /home/builder/Repos/ltp

CFLAGS += -Wall -I$(LTP_SRC)/include -I$(LTP_SRC)/include/old
LDFLAGS += -L$(LTP_SRC)/lib
LDLIBS += -lltp

all: mmap01

clean:
	rm -f mmap01 *.o