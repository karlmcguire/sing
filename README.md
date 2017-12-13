### sing

Fast string ring buffers.

### usage

```c
#include "sing.h"

int
main(void) {
    // create and initialize a buffer 
    struct sing_buffer b;
    init(&b);

    // push a string to the buffer
    sing_push(&b, "karl");

    // read a string from the buffer
    const char *karl = sing_shift(&b);
}
```
