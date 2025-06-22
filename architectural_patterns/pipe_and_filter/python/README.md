# Pipe and Filter pattern example in Python

## Key concepts

| Component  | Example Function       | Purpose                        |
| ---------- | ---------------------- | ------------------------------ |
| **Filter** | `remove_punctuation()` | Transforms or filters the data |
| **Pipe**   | `run_pipeline()`       | Passes data between filters    |
| **Data**   | `text → words`         | Flows through the filter chain |
