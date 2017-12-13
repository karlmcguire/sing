all:
	clang -DRING_CAP=4 -std=c99 ring.c -o ring