def log_decorator(func):
    def wrapper(*args, **kwargs):
        print(f"Calling '{func.__name__}' with args={args}, kwargs={kwargs}")
        result = func(*args, **kwargs)
        print(f"'{func.__name__}' returned {result}")
        return result
    return wrapper

@log_decorator
def add(x, y):
    return x + y

@log_decorator
def greet(name):
    return f"Hello, {name}!"

# Usage
if __name__ == "__main__":
    print(add(3, 4))
    print(greet(name="Alice"))
