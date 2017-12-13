#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sing.h"

void sing_init(struct sing_buffer *b) { 
	b->tail = SING_CAP;
	b->head = SING_CAP; 
}

int sing_push(struct sing_buffer *b, char *s) {
	if(sing_full(b))
		return 0;

	// get next index
	int i = (b->tail++) & SING_LEN;
	// get length of stsing
	int l = strlen(s) + 1;

	// free memory if already allocated
	if(!b->array[i])
		free(b->array[i]);

	// allocate length of stsing
	b->array[i] = malloc(l);
	// copy stsing
	strncpy(b->array[i], s, l);

	return 1;
}

char *sing_shift(struct sing_buffer *b) { 
	if(sing_empty(b))
		return "";

	return b->array[(b->head++) & SING_LEN]; 
}

int sing_empty(struct sing_buffer *b) {
	return b->head == b->tail;
}

int sing_full(struct sing_buffer *b) {
	return sing_size(b) == SING_CAP;
}

uint32_t sing_size(struct sing_buffer *b) { 
	return b->tail - b->head; 
}

int main() {
	struct sing_buffer b;
	sing_init(&b);

	sing_push(&b, "karl");
	printf("%s\n", sing_shift(&b));	
}
