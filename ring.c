#include <stdio.h>
#include <stdint.h>

// CAP must be a power of 2, using unsigned integer overflow
#define CAP 4
#define LEN CAP - 1

struct buffer {
	uint32_t read;
	uint32_t write;
	char array[CAP];
};

uint32_t mask(struct buffer *b, uint32_t i) {
	return i & LEN;
}

void push(struct buffer *b, char v) { 
	b->array[mask(b, b->write++)] = v;
}

char shift(struct buffer *b) {
	return b->array[mask(b, b->read++)];
}

struct buffer new() {
	struct buffer b;
	
	b.read = (uint32_t)LEN;
	for(uint32_t i = 0; i < CAP; i++) {
		b.array[i] = 0x00;
	}

	return b;
}

int main() {
	struct buffer r = new();

	push(&r, 'k');
	push(&r, 'a');
	push(&r, 'r');
	push(&r, 'l');

	printf("%c\n", shift(&r));
	printf("%c\n", shift(&r));
	printf("%c\n", shift(&r));
	printf("%c\n", shift(&r));
}