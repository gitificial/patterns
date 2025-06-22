# Implementor Interface
class Device:
    def is_on(self): pass
    def turn_on(self): pass
    def turn_off(self): pass
    def set_volume(self, volume): pass

# Concrete Implementor 1
class TV(Device):
    def __init__(self):
        self._on = False
        self._volume = 10

    def is_on(self): return self._on
    def turn_on(self): self._on = True; print("TV turned ON")
    def turn_off(self): self._on = False; print("TV turned OFF")
    def set_volume(self, volume): self._volume = volume; print(f"TV volume set to {volume}")

# Concrete Implementor 2
class Radio(Device):
    def __init__(self):
        self._on = False
        self._volume = 5

    def is_on(self): return self._on
    def turn_on(self): self._on = True; print("Radio turned ON")
    def turn_off(self): self._on = False; print("Radio turned OFF")
    def set_volume(self, volume): self._volume = volume; print(f"Radio volume set to {volume}")

# Abstraction
class RemoteControl:
    def __init__(self, device: Device):
        self.device = device

    def toggle_power(self):
        if self.device.is_on():
            self.device.turn_off()
        else:
            self.device.turn_on()

# Refined Abstraction
class AdvancedRemoteControl(RemoteControl):
    def volume_up(self):
        print("Increasing volume...")
        self.device.set_volume(15)

    def volume_down(self):
        print("Decreasing volume...")
        self.device.set_volume(5)

# --- Usage ---
if __name__ == "__main__":
    tv = TV()
    radio = Radio()

    remote = RemoteControl(tv)
    remote.toggle_power()   # Turn on TV

    advanced_remote = AdvancedRemoteControl(radio)
    advanced_remote.toggle_power()  # Turn on Radio
    advanced_remote.volume_up()     # Volume control
