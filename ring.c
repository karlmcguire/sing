#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ring.h"

void ring_init(struct ring_buffer *rb) { 
	rb->tail = RING_CAP;
	rb->head = RING_CAP; 
}

int ring_push(struct ring_buffer *rb, char *s) {
	if(ring_full(rb))
		return 0;

	// get next index
	int i = (rb->tail++) & RING_LEN;
	// get length of string
	int l = strlen(s) + 1;

	// free memory if already allocated
	if(!rb->array[i])
		free(rb->array[i]);

	// allocate length of string
	rb->array[i] = malloc(l);
	// copy string
	strncpy(rb->array[i], s, l);

	return 1;
}

char *ring_shift(struct ring_buffer *rb) { 
	if(ring_empty(rb))
		return "";

	return rb->array[(rb->head++) & RING_LEN]; 
}

int ring_empty(struct ring_buffer *rb) {
	return rb->head == rb->tail;
}

int ring_full(struct ring_buffer *rb) {
	return ring_size(rb) == RING_CAP;
}

uint32_t ring_size(struct ring_buffer *rb) { 
	return rb->tail - rb->head; 
}

int main() {
	struct ring_buffer rb;
	ring_init(&rb);

	ring_push(&rb, "karl");
	printf("%s\n", ring_shift(&rb));	
}