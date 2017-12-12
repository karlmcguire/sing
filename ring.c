#include <stdio.h>

struct buffer {
	int  read;
	int  write;
	int  capacity;
	char array[4];
};

int empty(struct buffer *b) {
	return b->read == b->write;
}

int size(struct buffer *b) {
	return b->write - b->read;
}

int full(struct buffer *b) {
	return size(b) == b->capacity;
}

int mask(struct buffer *b, int i) {
	return i & (b->capacity - 1);
}

int push(struct buffer *b, char v) { 
	b->array[mask(b, b->write++)] = v;
	return 0;
}

char shift(struct buffer *b) {
	return b->array[mask(b, b->read++)];
}

int main() {
	struct buffer r;
	r.capacity = 4;

	push(&r, 'k');
	printf("%c\n", shift(&r)); // 0x01 <- why?
	printf("%c\n", shift(&r)); // 0x00
	printf("%c\n", shift(&r)); // 0x00
	printf("%c\n", shift(&r)); // 'k'
}