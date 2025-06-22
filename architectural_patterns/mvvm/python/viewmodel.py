from model import CounterModel

class CounterViewModel:
    def __init__(self):
        self.model = CounterModel()
        self._observers = []

    def get_count_text(self):
        return str(self.model.get_value())

    def increment(self):
        self.model.increment()
        self._notify()

    def reset(self):
        self.model.reset()
        self._notify()

    def bind_to(self, callback):
        self._observers.append(callback)

    def _notify(self):
        for callback in self._observers:
            callback()
