# Subsystems (complex components)
class Amplifier:
    def on(self):
        print("Amplifier: ON")

    def set_volume(self, level):
        print(f"Amplifier: Volume set to {level}")

class DVDPlayer:
    def on(self):
        print("DVD Player: ON")

    def play(self, movie):
        print(f"DVD Player: Playing '{movie}'")

class Projector:
    def down(self):
        print("Projector: Screen lowered")

class Lights:
    def dim(self):
        print("Lights: Dimmed")

# Facade
class HomeTheaterFacade:
    def __init__(self, amp, dvd, projector, lights):
        self.amp = amp
        self.dvd = dvd
        self.projector = projector
        self.lights = lights

    def watch_movie(self, movie):
        print("\n[Facade] Starting movie setup...")
        self.lights.dim()
        self.projector.down()
        self.amp.on()
        self.amp.set_volume(5)
        self.dvd.on()
        self.dvd.play(movie)
        print("[Facade] Enjoy your movie!\n")

# --- Usage ---
if __name__ == "__main__":
    # Subsystem setup
    amp = Amplifier()
    dvd = DVDPlayer()
    projector = Projector()
    lights = Lights()

    # Facade
    theater = HomeTheaterFacade(amp, dvd, projector, lights)

    # Client only uses the Facade
    theater.watch_movie("Inception")
