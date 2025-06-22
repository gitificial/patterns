# Async State Machine in Rust

This project demonstrates an **asynchronous state machine pattern** in Rust using dynamic dispatch. It simulates a network client cycling through three states:

- `Disconnected`
- `Connecting`
- `Connected`

Each state transitions asynchronously using `async/await`, making it ideal for event-driven or embedded-style Rust development.

---

## Features

- Async trait-based state transitions
- Modular and extensible state design
- Clean separation of state behavior
- Compatible with async runtimes like `tokio`
- Easily adaptable for embedded async runtimes like [Embassy](https://embassy.dev/)

---

## 📦 Dependencies

This project uses:

- [`tokio`](https://docs.rs/tokio) – for async runtime
- [`async-trait`](https://docs.rs/async-trait) – to support `async fn` in traits

Install them with:

```toml
# Cargo.toml
[dependencies]
tokio = { version = "1.0", features = ["full"] }
async-trait = "0.1"

