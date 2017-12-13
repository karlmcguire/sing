# SING_CAP determines the capacity of the ring buffer -- it MUST be a power of
# 2 for performance reasons.
SING_CAP = 4

CC = clang
CFLAGS = -DSING_CAP=$(SING_CAP) -std=c99

SRC = sing.c
OBJ = sing.o

$(OBJ): $(SRC)
	$(CC) -c $(SRC) -o $(OBJ) $(CFLAGS)

clean:
	rm $(OBJ)
