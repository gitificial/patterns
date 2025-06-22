from viewmodel import CounterViewModel
from view import CounterView

if __name__ == "__main__":
    vm = CounterViewModel()
    view = CounterView(vm)
    view.mainloop()
