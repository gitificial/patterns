# Event-driven pattern

The Event-Driven Pattern is built around:
- Emitters that raise (emit) events.
- Listeners (handlers) that respond to those events.
- A dispatcher or event bus that connects them

## UML

```mermaid 
classDiagram 
    class EventBus {
         - listeners: Dict[str, List[Callable]] 
         + subscribe(event: str, callback: Callable) 
         + emit(event: str, data: Any) 
         } 
    class Listener { 
        + on_event(data: Any) 
        } 
    class Emitter { 
        + trigger_event() 
    } 
    
    EventBus --> Listener : notifies 
    Emitter --> EventBus : uses 
```