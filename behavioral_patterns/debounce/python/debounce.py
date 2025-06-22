import threading
import time

def debounce(wait_seconds):
    def decorator(fn):
        timer = None

        def debounced(*args, **kwargs):
            nonlocal timer
            if timer:
                timer.cancel()
            timer = threading.Timer(wait_seconds, fn, args=args, kwargs=kwargs)
            timer.start()
        return debounced
    return decorator

# Usage
@debounce(1.0)  # Wait 1 second of silence before executing
def on_button_press():
    print(f"Button action triggered at {time.time():.2f}")

# Simulate noisy button presses
if __name__ == "__main__":
    print("Simulating rapid button presses:")
    for _ in range(5):
        on_button_press()
        time.sleep(0.2)  # Less than debounce delay

    time.sleep(2)  # Allow time for final execution
