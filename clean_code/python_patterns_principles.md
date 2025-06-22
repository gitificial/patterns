# Clean Code Patterns/Principles in Python

| **Pattern / Principle**       | **Description**                                                               | **Example (Python)**                                                           |
|-------------------------------|-------------------------------------------------------------------------------|--------------------------------------------------------------------------------|
| **Single Responsibility**      | Each function/class should do one thing only                                  | `def read_sensor()` — not `read_and_log()`                                    |
| **Descriptive Naming**         | Use clear, meaningful names                                                   | `def calculate_checksum(data: bytes) -> int:`                                  |
| **Small Functions**            | Break long logic into short, focused functions                                | `def parse()`, `def validate()`, `def write()`                                 |
| **Early Return**               | Use `if` or `raise` early to avoid deep nesting                               | `if not data: return`                                                          |
| **Avoid Boolean Flags**        | Use multiple functions or enums instead of flags                              | `def log_info(msg)`, `def log_error(msg)` instead of `log(msg, is_error)`      |
| **Don’t Repeat Yourself (DRY)**| Extract common logic into helpers                                              | `def retry_operation()` instead of duplicating retry logic                     |
| **Limit Side Effects**         | Prefer pure functions that return values rather than modifying globals        | `def normalize(value): return (value - min) / range`                           |
| **Separation of Concerns**     | Keep data access, logic, and presentation separate                            | Use `models.py`, `services.py`, `ui.py`                                        |
| **No Magic Numbers**           | Use named constants                                                           | `MAX_RETRIES = 5`                                                               |
| **Comment Why, Not What**      | Comments should explain intent, not obvious code                              | `# Avoid divide-by-zero in case of bad input`                                  |
| **Consistent Error Handling**  | Use exceptions, context managers, and avoid silent failures                   | `try: ... except ValueError:`                                                  |
| **Consistent Formatting**      | Follow PEP 8 using linters/formatters                                         | Use `black`, `ruff`, or `flake8`                                               |
| **Self-Documenting Code**      | Use good naming and function signatures to make comments unnecessary          | `def download_file(url: str, timeout: float) -> bytes:`                        |
| **Assertive Interfaces**       | Use `assert` or `raise` to enforce assumptions early                          | `assert path.endswith('.csv')`                                                 |
| **Encapsulate Configuration**  | Store config in constants, `.env`, or `config.py`                             | `from config import TIMEOUT, API_URL`                                          |
| **Use Enumerations**           | Prefer `Enum` over raw strings or integers                                    | `from enum import Enum` → `class State(Enum): IDLE = 0`                        |
| **Use Classes or Dataclasses** | Group related data using `class` or `@dataclass`                              | `@dataclass class Point: x: int; y: int`                                       |
| **Testable Functions**         | Write small, pure functions with clear inputs and outputs                     | `def calculate_total(price, tax): return price * (1 + tax)`                    |

---

## Python-Specific Clean Code Practices

| **Pattern / Principle**         | **Description**                                                              |
|----------------------------------|-------------------------------------------------------------------------------|
| **PEP 8 Compliance**             | Follow Python’s official style guide                                         |
| **Use `with` for Resource Safety** | Use context managers for file/network access (`with open(...) as f:`)       |
| **Avoid `from module import *`** | Use explicit imports to improve clarity and avoid conflicts                 |
| **Prefer Exceptions over Return Codes** | Use `raise` instead of returning `None` on errors                     |
| **Use Properties Instead of Getter/Setter** | Use `@property` for clean attribute access                      |
| **Use Docstrings**              | Use triple-quoted `"""docstrings"""` for modules, classes, and functions     |
| **Avoid Global State**          | Minimize global variables — pass explicitly or encapsulate in objects        |
| **Use `enumerate()` and `zip()`**| Avoid manual counters or indexing where unnecessary                         |
| **Use Comprehensions**          | Prefer list/set/dict comprehensions over verbose loops                       |
| **Prefer F-Strings**            | Use `f"{name}"` instead of `%` or `.format()`                                |

---

## Tools That Help Enforce Clean Code in Python

| Tool         | Purpose                     |
|--------------|-----------------------------|
| `black`      | Code formatter               |
| `flake8`     | Linter for style and errors  |
| `mypy`       | Static type checking         |
| `pylint`     | Code analysis and style hints|
| `pytest`     | Testing framework            |
| `ruff`       | Fast linter + formatter combo|

