# SING_CAP determines the capacity of the ring buffer -- it MUST be a power of
# 2 for performance reasons.
SING_CAP = 4

AR = ar
CC = clang
CFLAGS = -DSING_CAP=$(SING_CAP) -std=c99 -fPIC
PREFIX = /usr/local

SRC = sing.c
OBJ = sing.o
LIB = sing.a
HEADER = sing.h

.PHONY: all
all: ${LIB}

$(LIB): $(OBJ)
	$(AR) rcs $@ $^

$(OBJ): $(SRC)
	$(CC) -c $(SRC) -o $(OBJ) $(CFLAGS)

install: $(LIB)
	mkdir -p $(DESTDIR)$(PREFIX)/lib
	mkdir -p $(DESTDIR)$(PREFIX)/include
	cp $(LIB) $(DESTDIR)$(PREFIX)/lib/$(LIB)
	cp $(HEADER) $(DESTDIR)$(PREFIX)/include/

clean:
	rm $(OBJ) $(LIB)
