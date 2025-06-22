from typing import Callable, Dict

class Broker:
    def __init__(self):
        self.services: Dict[str, Callable[[str], None]] = {}

    def register_service(self, name: str, handler: Callable[[str], None]):
        self.services[name] = handler
        print(f"[Broker] Registered service: {name}")

    def dispatch(self, name: str, payload: str):
        if name in self.services:
            print(f"[Broker] Dispatching to service: {name}")
            self.services[name](payload)
        else:
            print(f"[Broker] No service found for: {name}")

# Define services
def log_service(payload: str):
    print(f"[Log Service] {payload}")

def alert_service(payload: str):
    print(f"[Alert Service] !! {payload} !!")

# Simulate a client application
if __name__ == "__main__":
    broker = Broker()

    broker.register_service("log", log_service)
    broker.register_service("alert", alert_service)

    broker.dispatch("log", "System is up")
    broker.dispatch("alert", "High temperature detected")
    broker.dispatch("unknown", "This will fail")