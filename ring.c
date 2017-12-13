#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// CAP must be a power of 2 (using uint32_t overflow)
#define CAP 4
#define LEN CAP - 1

struct ring {
	uint32_t head;
	uint32_t tail;
	char *array[CAP];
};

/* push adds an element to the tail of the ring buffer */
void push(struct ring *r, char *v) {
	// get next index
	int i = (r->tail++) & LEN;
	// get length of string
	int l = strlen(v) + 1;

	// free memory if already allocated
	if(!r->array[i])
		free(r->array[i]);

	// allocate length of string
	r->array[i]	= malloc(l);
	// copy string
	strncpy(r->array[i], v, l);
}

/* shift returns the element from the head of the ring buffer */
char *shift(struct ring *r) { 
	return r->array[(r->head++) & LEN]; 
}

/* init sets up the ring tail field for pushing/shifting */
void init(struct ring *r) { 
	r->tail = (uint32_t)CAP; 
	r->head = (uint32_t)CAP;
}

uint32_t size(struct ring *r) { return r->tail - r->head; }
int empty(struct ring *r) { return r->head == r->tail;	}
int full(struct ring *r) { return size(r) == (uint32_t)CAP; }

int main() {
	struct ring r;
	init(&r);

	push(&r, "karl");
	push(&r, "noah");
	push(&r, "finn");
	push(&r, "max");

	printf("%s\n", shift(&r));
	printf("%s\n", shift(&r));
	printf("%s\n", shift(&r));
	printf("%s\n", shift(&r));
}