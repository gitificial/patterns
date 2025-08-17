# Containers

A container is a data structure that stores elements e.g. of type integer, bool, etc.

It supports:
- Adding (push_back)
- Accessing ([])
- Iterating (for loop)
- Querying properties (size())

## Associative Containers in C++

| Container       | Description                             |
| --------------- | --------------------------------------- |
| `std::set`      | Stores **unique keys**, sorted          |
| `std::map`      | Stores **key-value pairs**, unique keys. <br> Logarithmic time complexity for insert/search/delete. <br> Automatically sorted by key (default: operator<). <br> Useful for configuration tables, routing maps, inventories, etc. |
| `std::multiset` | Allows duplicate keys                   |
| `std::multimap` | Allows duplicate keys                   |


## Contiguous Containers in C++

| Container           | Description                             |
| ------------------- | --------------------------------------- |
| `std::vector`       | Dynamically sized array (most common). <br> Fast random access. <br> Compatible with C libraries (&vec[0] is like a C array). <br> Good performance for SIMD/vectorized operations.|
| `std::array`        | Fixed-size array (stack-allocated)      |
| `std::string`       | Contiguous array of characters          |
| `std::span` (C++20) | Non-owning view over a contiguous range |

## Reversible Containers in C++

| Container              | Supports Reverse Iteration? | Notes                          |
| ---------------------- | --------------------------- | ------------------------------ |
| `std::vector`          | Yes                       | Contiguous and reversible      |
| `std::deque`           | Yes                       | Double-ended queue             |
| `std::list`            | Yes                       | Doubly linked list             |
| `std::map`, `std::set` | Yes                       | Associative, sorted containers |

## Standard Sequence Containers in C++

| Container           | Characteristics                                         |
| ------------------- | ------------------------------------------------------- |
| `std::vector`       | Dynamic array, fast random access                       |
| `std::deque`        | Double-ended queue, fast front/back insertions          |
| `std::list`         | Doubly-linked list, efficient inserts/removals anywhere |
| `std::forward_list` | Single-linked list (C++11)                              |
| `std::array`        | Fixed-size array (stack allocated)                      |

When to use which:

| Container           | Use When You Need…                        |
| ------------------- | ----------------------------------------- |
| `std::vector`       | Fast access by index, mostly back inserts |
| `std::deque`        | Fast insert/remove at both ends           |
| `std::list`         | Many inserts/removes in the middle        |
| `std::forward_list` | Lower memory usage, one-directional ops   |
| `std::array`        | Fixed-size, no dynamic allocation         |
