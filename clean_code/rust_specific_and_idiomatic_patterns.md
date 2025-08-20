## Rust-Specific and Idiomatic Patterns

Rust encourages patterns that take advantage of its ownership model, zero-cost abstractions, and rich type system.

---

## Core Rust Patterns and Idioms

| **Pattern / Idiom**            | **Description** |
|--------------------------------|-----------------|
| **Ownership & Borrowing**      | Enforces memory safety at compile time via `&`, `Box`, `Rc`, `Arc`. |
| **RAII (Resource Acquisition Is Initialization)** | Automatic resource cleanup via `Drop`, used for files, locks, hardware, etc. |
| **Zero-Cost Abstractions**     | Compile-time optimizations make abstractions (traits, generics) free at runtime. |
| **Newtype Pattern**            | Wraps existing types in a tuple struct to enforce type safety or add behavior. |
| **Builder Pattern**            | Construct complex objects with chained methods (often uses `#[derive(Default)]`). |
| **From / Into / TryFrom**      | Idiomatic conversion between types using traits (`From<T>`, `Into<T>`, etc.). |
| **Error Handling with `Result` & `?`** | Clean, early-exit error propagation using `Result<T, E>` and `?` operator. |
| **PhantomData**                | Tells the compiler about unused type parameters or lifetimes. |
| **Type-State Pattern**         | Encodes valid transitions in types (e.g., `NotConnected` → `Connected`). |
| **Typestate-based APIs**       | Prevents misuse at compile time by disallowing invalid state transitions. |
| **Smart Pointer Patterns**     | Use of `Box`, `Rc`, `RefCell`, `Arc` to control ownership and mutability. |
| **Interior Mutability**        | Enables mutation via shared references using `Cell`, `RefCell`, or `Mutex`. |
| **Crate-local Visibility (`pub(crate)`)** | Exposes items within the crate for controlled encapsulation. |
| **Iterator Pattern**           | Chainable, lazy computation using the `Iterator` trait. |
| **State Machine with `enum`**  | Replaces OOP polymorphism with `match` on enums to model behavior. |
| **No-Std Development**         | For embedded systems without `std`, using `core` and `alloc` crates. |
| **Async/Await with Pin & Future** | Memory-safe, zero-cost concurrency using the `Future` trait and `Pin`. |
| **Functional Composition**     | Uses closures and combinators like `map`, `filter`, `fold`. |
| **Macro-Based DSLs**           | Powerful compile-time logic using procedural and derive macros (`serde`, `nom`, etc.). |

---

## Ecosystem Patterns and Practices

| **Pattern**             | **Used In** |
|-------------------------|-------------|
| `#[derive(...)]` macros | `serde`, `clap`, `Debug`, `Clone`, etc. |
| `builder` pattern       | `reqwest::ClientBuilder`, `tokio::RuntimeBuilder` |
| `async` with `.await`   | `tokio`, `async-std`, `embassy` |
| `trait objects`         | `dyn Trait` for plugin systems or GUIs |
| `actor model`           | `actix`, `tokio::mpsc`, `riker` |
| `pinning` pattern       | `futures`, `tokio` |
| `no_std` + `embedded-hal` | `stm32-hal`, `nrf-hal`, `embassy` |

---

## Commonly Used Crates

- [`serde`](https://serde.rs/) – Serialization via macros and traits
- [`tokio`](https://tokio.rs/) – Async runtime with I/O and scheduling
- [`nom`](https://github.com/Geal/nom) – Parser combinator DSL
- [`embassy`](https://embassy.dev/) – Async embedded development
- [`heapless`](https://docs.rs/heapless) – Fixed-capacity collections (no `std`)

---

## Summary

Rust’s idiomatic patterns focus on:

- Compile-time correctness
- Memory and thread safety
- Composability and modularity
- Minimal runtime overhead

Many classic OOP design patterns are replaced or reimagined through **traits, enums, lifetimes, and ownership**.