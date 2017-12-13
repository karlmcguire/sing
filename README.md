### sing

Fast string ring buffers.

### usage

```c
// create and initialize a buffer 
struct sing_buffer b;
sing_init(&b);

// push a string to the buffer
sing_push(&b, "karl");

// read a string from the buffer
char *karl = sing_shift(&b);
```

### todo

* concurrency/thread safe
* more data types
