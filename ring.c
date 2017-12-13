#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// CAP must be a power of 2 (using uint32_t overflow)
#define CAP (uint32_t)4
#define LEN CAP - (uint32_t)1

struct ring {
	uint32_t head;
	uint32_t tail;
	char *array[CAP];
};

/* size returns the number of unread objects in the ring buffer */
uint32_t size(struct ring *r) { 
	return r->tail - r->head; 
}

/* empty returns 1 if the ring buffer is empty, 0 if not */
int empty(struct ring *r) {
	return r->head == r->tail;
}

/* full returns 1 if the ring buffer is full, 0 if not */
int full(struct ring *r) {
	return size(r) == CAP;
}

/* push adds an element to the tail of the ring buffer */
int push(struct ring *r, char *v) {
	if(full(r))
		return 0;

	// get next index
	int i = (r->tail++) & LEN;
	// get length of string
	int l = strlen(v) + 1;

	// free memory if already allocated
	if(!r->array[i])
		free(r->array[i]);

	// allocate length of string
	r->array[i] = malloc(l);
	// copy string
	strncpy(r->array[i], v, l);

	return 1;
}

/* shift returns the element from the head of the ring buffer */
char *shift(struct ring *r) { 
	if(empty(r))
		return "";

	return r->array[(r->head++) & LEN]; 
}

/* init sets up the ring tail field for pushing/shifting */
void init(struct ring *r) { 
	r->tail = CAP;
	r->head = CAP; 
}

int main() {
	struct ring r;
	init(&r);

	push(&r, "karl");
	printf("%s\n", shift(&r));	
}