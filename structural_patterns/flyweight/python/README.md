# Flyweight example in Python

- Minimize memory use by sharing data between similar objects.
- Ideal when you have a large number of objects with shared internal state.

## Example description
Drawing thousands of trees in a game. Each tree has:
- Shared data: species name, texture, color (intrinsic state).
- Unique data: x/y position, height, etc. (extrinsic state)

- TreeType: Flyweight (shared state)
- TreeFactory: Flyweight Factory (manages reuse)
- Tree: Context (extrinsic data: x/y)
- Forest: Client (uses shared flyweights)