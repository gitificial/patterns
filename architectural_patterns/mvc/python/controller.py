from model import TodoModel
from view import TodoView

class TodoController:
    def __init__(self):
        self.model = TodoModel()
        self.view = TodoView()

    def run(self):
        while True:
            self.view.show_items(self.model.get_items())
            new_item = self.view.prompt_new_item()
            if new_item.lower() in ['exit', 'quit']:
                break
            self.model.add_item(new_item)
            self.view.show_added_message(new_item)
