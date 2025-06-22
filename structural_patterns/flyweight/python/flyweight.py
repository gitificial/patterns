# Flyweight (shared object)
class TreeType:
    def __init__(self, name, color, texture):
        self.name = name
        self.color = color
        self.texture = texture

    def draw(self, x, y):
        print(f"Drawing a {self.name} tree at ({x}, {y}) with color {self.color} and texture {self.texture}")

# Flyweight Factory
class TreeFactory:
    _tree_types = {}

    @staticmethod
    def get_tree_type(name, color, texture):
        key = (name, color, texture)
        if key not in TreeFactory._tree_types:
            print(f"Creating new TreeType: {key}")
            TreeFactory._tree_types[key] = TreeType(name, color, texture)
        return TreeFactory._tree_types[key]

# Context object (has extrinsic data)
class Tree:
    def __init__(self, x, y, tree_type):
        self.x = x
        self.y = y
        self.type = tree_type

    def draw(self):
        self.type.draw(self.x, self.y)

# Client
class Forest:
    def __init__(self):
        self.trees = []

    def plant_tree(self, x, y, name, color, texture):
        tree_type = TreeFactory.get_tree_type(name, color, texture)
        tree = Tree(x, y, tree_type)
        self.trees.append(tree)

    def draw_forest(self):
        for tree in self.trees:
            tree.draw()

# --- Usage ---
if __name__ == "__main__":
    forest = Forest()

    # Plant many trees of the same type
    forest.plant_tree(10, 20, "Oak", "Green", "Rough")
    forest.plant_tree(30, 40, "Oak", "Green", "Rough")
    forest.plant_tree(50, 60, "Pine", "Dark Green", "Smooth")

    print("\nDrawing forest:")
    forest.draw_forest()
