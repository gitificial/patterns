# Clean Code Patterns/Principles in Rust

| **Pattern / Principle**       | **Description**                                                                 | **Example (Rust)**                                                              |
|-------------------------------|----------------------------------------------------------------------------------|----------------------------------------------------------------------------------|
| **Single Responsibility**      | A function or struct should do one clear thing                                  | `fn read_sensor()` — not `read_and_log_sensor()`                                |
| **Descriptive Naming**         | Use clear, expressive names for functions and variables                         | `fn calculate_checksum(data: &[u8]) -> u8`                                       |
| **Small Functions**            | Functions should be short and focused                                           | `fn parse()`, `fn validate()`, `fn save()` instead of a 50-line `fn process()`   |
| **Early Return**               | Use `if let`, `match`, or `?` to return early                                   | `let data = read()?;`                                                            |
| **Avoid Boolean Flags**        | Use enums instead of booleans                                                   | `fn log(message: &str, level: LogLevel)` vs `fn log(msg: &str, error: bool)`     |
| **Don’t Repeat Yourself (DRY)**| Reuse logic via functions, traits, or macros                                    | `impl Display for Point { ... }`                                                |
| **Limit Side Effects**         | Prefer pure functions, avoid unexpected changes                                 | `fn compute(x: i32) -> i32` instead of modifying global state                    |
| **Separation of Concerns**     | Split logic into layers/modules                                                 | `mod sensor`, `mod ui`, `mod comm`                                               |
| **No Magic Numbers**           | Replace literals with named `const` or `enum` values                            | `const TIMEOUT_MS: u64 = 100;`                                                   |
| **Comment Why, Not What**      | Explain non-obvious behavior or rationale                                       | `// Using retry to handle flaky sensor read`                                     |
| **Consistent Error Handling**  | Use `Result<T, E>` and `?` consistently                                         | `fn load_file() -> Result<String, io::Error>`                                    |
| **Consistent Formatting**      | Use `rustfmt` for standard style                                                | Auto-formatted with `cargo fmt`                                                  |
| **Self-Documenting Code**      | Let types and names explain the code                                            | `struct SensorReading { temperature: f32, humidity: f32 }`                       |
| **Assertive Interfaces**       | Use `assert!`, `debug_assert!`, or type safety                                  | `assert!(value < 100);`                                                          |
| **Encapsulate Configuration**  | Use `struct Config`, `const`, or `lazy_static!`                                 | `struct Config { retries: u8, delay_ms: u64 }`                                   |
| **Use Enumerations**           | Use `enum` instead of string or numeric flags                                   | `enum State { Idle, Running, Error }`                                            |
| **Use Structs to Group Data**  | Group related fields using `struct`                                             | `struct User { name: String, age: u8 }`                                          |
| **Testable Functions**         | Write pure, side-effect-free functions where possible                           | `fn add(a: i32, b: i32) -> i32`                                                  |

---

## Additional Rust-Specific Clean Code Principles

| **Rust Pattern / Principle**  | **Description**                                                                 |
|-------------------------------|----------------------------------------------------------------------------------|
| **Use `Option` and `Result`** | Avoid `null` and error-prone patterns; use types to enforce safety              |
| **Prefer Pattern Matching**   | Use `match`, `if let`, `while let` for clear control flow                       |
| **Prefer Immutability**       | Declare variables with `let` unless mutation is needed                          |
| **Encourage Ownership Clarity**| Make ownership and lifetimes explicit through naming and signatures              |
| **Leverage Traits for Abstraction** | Use traits to decouple interfaces from implementations                 |
| **Avoid `.unwrap()` in Logic**| Use `?`, `match`, or `expect()` with a message                                  |
| **Use Iterator Combinators**  | Prefer `map`, `filter`, `fold` over manual loops for clarity                    |
| **Minimize `unsafe`**         | Use `unsafe` only when absolutely necessary and document its correctness        |
| **Group Code with `mod`**     | Organize files and modules clearly using `mod` and `pub use`                    |

---

## Tools That Enforce These Patterns

- `cargo fmt` – automatic formatting
- `cargo clippy` – idiomatic linting
- `cargo test` – built-in unit testing
- `cargo doc` – generates API documentation from code comments

