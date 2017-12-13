#define RING_LEN RING_CAP - 1

struct ring_buffer {
	uint32_t head;
	uint32_t tail;
	char *array[RING_CAP];
};

void ring_init(struct ring_buffer *rb);

int ring_push(struct ring_buffer *rb, char *s);
char *ring_shift(struct ring_buffer *rb);

int ring_full(struct ring_buffer *rb);
int ring_empty(struct ring_buffer *rb);
uint32_t ring_size(struct ring_buffer *rb);