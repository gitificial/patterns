# Ring buffer (circular buffer) example in C

## Explanation
- head points to the next write index.
- tail points to the next read index.
- count tracks how many elements are in the buffer.
- When head or tail reaches the end, it wraps around (modulo buffer size).
- Prevents overwriting unread data by checking if full before enqueue.

## Compile and run
```
gcc main.c -o ring_buffer
./ring_buffer
```

