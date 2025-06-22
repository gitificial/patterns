class TodoModel:
    def __init__(self):
        self.todos = []

    def add_item(self, item: str):
        self.todos.append(item)

    def get_items(self):
        return self.todos.copy()
