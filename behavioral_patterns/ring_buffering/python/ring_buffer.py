class RingBuffer:
    def __init__(self, size):
        self.size = size
        self.buffer = [None] * size
        self.head = 0  # Next write position
        self.tail = 0  # Next read position
        self.count = 0

    def is_full(self):
        return self.count == self.size

    def is_empty(self):
        return self.count == 0

    def append(self, value):
        if self.is_full():
            print("Buffer full! Overwriting oldest value.")
            self.tail = (self.tail + 1) % self.size  # Overwrite oldest
        else:
            self.count += 1

        self.buffer[self.head] = value
        self.head = (self.head + 1) % self.size

    def get(self):
        if self.is_empty():
            print("Buffer empty!")
            return None
        value = self.buffer[self.tail]
        self.tail = (self.tail + 1) % self.size
        self.count -= 1
        return value

    def __str__(self):
        return f"Buffer: {self.buffer} | Head: {self.head}, Tail: {self.tail}, Count: {self.count}"


# --- Test the ring buffer ---
if __name__ == "__main__":
    rb = RingBuffer(5)

    for i in range(1, 7):
        print(f"Appending {i}")
        rb.append(i)
        print(rb)

    print("\nReading values:")
    for _ in range(6):
        value = rb.get()
        print(f"Got: {value}")
        print(rb)
