import time

class DoubleBuffer:
    def __init__(self, size):
        self.buffer1 = [0] * size
        self.buffer2 = [0] * size
        self.front = self.buffer1
        self.back = self.buffer2

    def write_to_back(self, data):
        print(f"Writing to back buffer: {data}")
        for i in range(len(self.back)):
            self.back[i] = data + i  # simulate filling buffer with data

    def display_front(self):
        print(f"Displaying front buffer: {self.front}")

    def swap_buffers(self):
        self.front, self.back = self.back, self.front
        print("Buffers swapped.")

def main():
    buffer = DoubleBuffer(size=5)

    for frame in range(3):  # simulate 3 frames
        print(f"\n--- Frame {frame + 1} ---")
        buffer.write_to_back(data=frame * 10)
        time.sleep(0.5)  # simulate processing delay
        buffer.swap_buffers()
        buffer.display_front()

if __name__ == "__main__":
    main()
