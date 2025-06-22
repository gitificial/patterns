# Subject (Observable)
class WeatherStation:
    def __init__(self):
        self._observers = []
        self._temperature = None

    def add_observer(self, observer):
        self._observers.append(observer)

    def remove_observer(self, observer):
        self._observers.remove(observer)

    def set_temperature(self, temp):
        print(f"\n[WeatherStation] Temperature changed to {temp}°C")
        self._temperature = temp
        self._notify_observers()

    def _notify_observers(self):
        for observer in self._observers:
            observer.update(self._temperature)


# Observer Interface
class Observer:
    def update(self, temp):
        raise NotImplementedError


# Concrete Observers
class PhoneDisplay(Observer):
    def update(self, temp):
        print(f"[PhoneDisplay] Updated temperature: {temp}°C")


class WindowDisplay(Observer):
    def update(self, temp):
        print(f"[WindowDisplay] Updated temperature: {temp}°C")


# --- Usage Example ---
if __name__ == "__main__":
    station = WeatherStation()

    phone = PhoneDisplay()
    window = WindowDisplay()

    station.add_observer(phone)
    station.add_observer(window)

    station.set_temperature(22.5)
    station.set_temperature(25.0)

    station.remove_observer(phone)
    station.set_temperature(28.0)
