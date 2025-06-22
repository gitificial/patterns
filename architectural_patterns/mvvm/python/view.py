import tkinter as tk

class CounterView(tk.Tk):
    def __init__(self, viewmodel):
        super().__init__()
        self.viewmodel = viewmodel
        self.title("MVVM Counter")

        self.label = tk.Label(self, text=self.viewmodel.get_count_text(), font=("Arial", 24))
        self.label.pack(pady=10)

        self.increment_button = tk.Button(self, text="Increment", command=self.viewmodel.increment)
        self.increment_button.pack(pady=5)

        self.reset_button = tk.Button(self, text="Reset", command=self.viewmodel.reset)
        self.reset_button.pack(pady=5)

        self.viewmodel.bind_to(self.update_view)

    def update_view(self):
        self.label.config(text=self.viewmodel.get_count_text())
