#define SING_LEN SING_CAP - 1

struct sing_buffer {
	uint32_t head;
	uint32_t tail;
	char *array[SING_CAP];
};

void sing_init(struct sing_buffer *b);

int sing_push(struct sing_buffer *b, char *s);
char *sing_shift(struct sing_buffer *b);

int sing_full(struct sing_buffer *b);
int sing_empty(struct sing_buffer *b);
uint32_t sing_size(struct sing_buffer *b);
