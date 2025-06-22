# Debounce Pattern in Rust (Async)

This project demonstrates a clean and testable **debounce logic pattern** in Rust using `async` and `tokio`. Debouncing is a common requirement in **embedded systems**, **input signal filtering**, or **button press detection**, where noisy input signals (like mechanical buttons) can generate multiple rapid state changes that should be ignored.

---

## Features

- Asynchronous debounce logic using `tokio`
- Filters noisy inputs (e.g., bouncing buttons)
- Easily extendable to embedded environments (e.g., [`embassy`](https://embassy.dev/))
- Demonstrates clean input filtering logic

---

## Dependencies

```toml
[dependencies]
tokio = { version = "1.0", features = ["time", "macros"] }

