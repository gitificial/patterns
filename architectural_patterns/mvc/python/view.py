class TodoView:
    def show_items(self, items):
        print("\nYour Todo List:")
        for idx, item in enumerate(items, 1):
            print(f"{idx}. {item}")

    def prompt_new_item(self):
        return input("Enter a new todo item: ")

    def show_added_message(self, item):
        print(f"Added: '{item}'")
