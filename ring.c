#include <stdio.h>
#include <stdint.h>
#include <time.h>

// CAP must be a power of 2 (using uint32_t overflow)
#define CAP 4
#define LEN CAP - 1

struct ring {
	uint32_t head;
	uint32_t tail;
	char array[CAP];
};

/* push adds an element to the tail of the ring buffer */
void push(struct ring *r, char v) { r->array[(r->tail++) & LEN] = v; }

/* shift returns the element from the head of the ring buffer */
char shift(struct ring *r) { return r->array[(r->head++) & LEN]; }

/* init sets up the ring tail field for pushing/shifting */
void init(struct ring *r) { r->tail = (uint32_t)CAP; }

int main() {
	struct ring r;
	init(&r);

	push(&r, 'k');
	printf("%c", shift(&r));
	push(&r, 'a');
	printf("%c", shift(&r));
	push(&r, 'r');
	printf("%c", shift(&r));
	push(&r, 'l');
	printf("%c\n", shift(&r));
}