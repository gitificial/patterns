# Composite pattern

- Treat individual objects and groups of objects uniformly.
- Build tree-like structures where clients interact with single items and composites the same way.

- FileSystemComponent: Abstract component interface
- File (Leaf): Basic element with no children
- Folder (Composite): Container with children
- Client: Treats leaf and composite uniformly