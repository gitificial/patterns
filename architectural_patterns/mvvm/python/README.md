## What it does
- GUI starts with 0
- Clicking Increment calls ViewModel.increment(), updates Model, notifies View
- Clicking Reset resets counter in Model via ViewModel

## File overview
```
mvvm_example/
├── model.py
├── viewmodel.py
├── view.py
└── main.py
```

## UML

```mermaid
classDiagram
    class CounterModel {
        - count: int
        + increment()
        + reset()
        + get_value() int
    }

    class CounterViewModel {
        - model: CounterModel
        - _observers: list
        + get_count_text() str
        + increment()
        + reset()
        + bind_to(callback)
    }

    class CounterView {
        - viewmodel: CounterViewModel
        - label
        - buttons
        + update_view()
    }

    CounterViewModel --> CounterModel : uses
    CounterView --> CounterViewModel : binds to
```