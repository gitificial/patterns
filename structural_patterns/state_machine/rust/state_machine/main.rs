use std::rc::Rc;
use std::cell::RefCell;

// ---- Trait defining behavior for each state ----
trait DoorState {
    fn open(self: Box<Self>) -> Box<dyn DoorState>;
    fn close(self: Box<Self>) -> Box<dyn DoorState>;
    fn status(&self) -> &'static str;
}

// ---- Concrete State: Closed ----
struct Closed;

impl DoorState for Closed {
    fn open(self: Box<Self>) -> Box<dyn DoorState> {
        println!("Door is now OPEN.");
        Box::new(Open)
    }

    fn close(self: Box<Self>) -> Box<dyn DoorState> {
        println!("Door is already CLOSED.");
        self
    }

    fn status(&self) -> &'static str {
        "Closed"
    }
}

// ---- Concrete State: Open ----
struct Open;

impl DoorState for Open {
    fn open(self: Box<Self>) -> Box<dyn DoorState> {
        println!("Door is already OPEN.");
        self
    }

    fn close(self: Box<Self>) -> Box<dyn DoorState> {
        println!("Door is now CLOSED.");
        Box::new(Closed)
    }

    fn status(&self) -> &'static str {
        "Open"
    }
}

// ---- Context: Door ----
struct Door {
    state: Box<dyn DoorState>,
}

impl Door {
    fn new() -> Self {
        Door {
            state: Box::new(Closed),
        }
    }

    fn open(&mut self) {
        self.state = self.state.open();
    }

    fn close(&mut self) {
        self.state = self.state.close();
    }

    fn status(&self) {
        println!("Door status: {}", self.state.status());
    }
}

// ---- Main Demo ----
fn main() {
    let mut door = Door::new();
    door.status();     // Closed
    door.open();       // Transition to Open
    door.status();     // Open
    door.open();       // Already open
    door.close();      // Transition to Closed
    door.status();     // Closed
}
