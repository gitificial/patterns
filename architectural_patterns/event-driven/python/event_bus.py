# Simple Event Bus
class EventBus:
    def __init__(self):
        self.listeners = {}

    def subscribe(self, event_name, callback):
        if event_name not in self.listeners:
            self.listeners[event_name] = []
        self.listeners[event_name].append(callback)

    def emit(self, event_name, data=None):
        if event_name in self.listeners:
            for callback in self.listeners[event_name]:
                callback(data)

# Event Handlers
def handle_user_registered(data):
    print(f"[Listener] Welcome email sent to {data['username']}")

def handle_user_logged_in(data):
    print(f"[Listener] Audit log: {data['username']} logged in")

# Client Code
if __name__ == "__main__":
    bus = EventBus()

    # Subscribe to events
    bus.subscribe("user_registered", handle_user_registered)
    bus.subscribe("user_logged_in", handle_user_logged_in)

    # Emit events
    print("Registering user...")
    bus.emit("user_registered", {"username": "alice"})

    print("User logging in...")
    bus.emit("user_logged_in", {"username": "alice"})
