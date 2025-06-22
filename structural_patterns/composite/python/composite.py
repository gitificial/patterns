from abc import ABC, abstractmethod

# Component Interface
class FileSystemComponent(ABC):
    @abstractmethod
    def display(self, indent=0):
        pass

# Leaf
class File(FileSystemComponent):
    def __init__(self, name):
        self.name = name

    def display(self, indent=0):
        print('  ' * indent + f"File: {self.name}")

# Composite
class Folder(FileSystemComponent):
    def __init__(self, name):
        self.name = name
        self.children = []

    def add(self, component: FileSystemComponent):
        self.children.append(component)

    def display(self, indent=0):
        print('  ' * indent + f"Folder: {self.name}")
        for child in self.children:
            child.display(indent + 1)

# --- Usage ---
if __name__ == "__main__":
    # Create files and folders
    file1 = File("file1.txt")
    file2 = File("file2.txt")
    subfolder = Folder("SubFolder")
    subfolder.add(File("file3.txt"))

    root_folder = Folder("Root")
    root_folder.add(file1)
    root_folder.add(subfolder)
    root_folder.add(file2)

    # Display tree structure
    root_folder.display()
