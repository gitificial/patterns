# Clean Code Patterns/Principles in C

| **Pattern / Principle**      | **Description**                                                                 | **Example (C)**                                                                 |
|-----------------------------|----------------------------------------------------------------------------------|---------------------------------------------------------------------------------|
| **Single Responsibility**    | A function/module should do one thing only                                      | `void read_sensor();` — Not `read_and_log_sensor();`                           |
| **Descriptive Naming**       | Use clear, intention-revealing names                                            | `int calculate_checksum(uint8_t *data, size_t len);`                           |
| **Small Functions**          | Break logic into small, focused functions                                       | `init_uart();`, `send_char();`, `flush_uart();` instead of one large function |
| **Early Return**             | Return early to reduce nesting and improve clarity                             | `if (ptr == NULL) return ERROR;`                                               |
| **Avoid Boolean Flags**      | Use separate functions instead of flags                                         | `log_error(msg);` vs. `log_message(msg, true);`                                |
| **Don't Repeat Yourself**    | Extract repeated code into a function or macro                                  | `retry_connection();` instead of duplicating retry logic                       |
| **Limit Side Effects**       | Minimize use of globals or external state                                       | `int sum(int a, int b);` — no hidden modification                              |
| **Separation of Concerns**   | Keep hardware, logic, and UI layers separate                                    | `read_sensor()` doesn't printf; use `format_sensor_data()`                     |
| **No Magic Numbers**         | Replace literals with named constants                                           | `#define MAX_RETRIES 3`                                                        |
| **Comment Why, Not What**    | Explain purpose or reasoning, not the obvious                                   | `// Clamp to avoid overcurrent damage`                                         |
| **Consistent Error Handling**| Use the same pattern for handling failures                                       | `if (status != OK) return ERROR;`                                              |
| **Consistent Formatting**    | Follow a standard code style                                                    | 4-space indent, braces on new line, clear block separation                     |
| **Self-Documenting Code**    | Code that explains itself via names and structure                               | `typedef struct { int x, y; } Point;`                                          |
| **Assertive Interfaces**     | Use assertions to catch invalid usage during development                        | `assert(ptr != NULL);`                                                         |
| **Encapsulate Config**       | Keep tunables like buffer sizes or GPIO pins in one place                       | `#define UART_BAUD 115200` in `config.h`                                       |
| **Use Enumerations**         | Improves clarity over integer constants                                         | `enum State { IDLE, RUNNING, ERROR };`                                         |
| **Use Structs to Group Data**| Combine related fields into a struct                                             | `typedef struct { int temp, humidity; } SensorData;`                           |
| **Testable Functions**       | Write pure, stateless functions where possible                                  | `int add(int a, int b);` — no global dependencies                              |
