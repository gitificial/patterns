# Model-View-Controller (MVC) pattern


## MVC Structure Overview
| Layer          | Responsibility                                            |
| -------------- | --------------------------------------------------------- |
| **Model**      | Manages data, logic, and rules                            |
| **View**       | Handles output (UI, console, web, etc.)                   |
| **Controller** | Handles user input and coordinates between model and view |

## UML

```mermaid
classDiagram
    class Model {
        +data
        +add_item(item)
        +get_items()
    }

    class View {
        +show_items(items)
        +prompt_new_item()
        +show_added_message(item)
    }

    class Controller {
        -model: Model
        -view: View
        +run()
    }

    Controller --> Model : uses
    Controller --> View : uses
```
