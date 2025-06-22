use std::time::Duration;
use async_trait::async_trait;
use tokio::time::sleep;

// ---- Trait representing an async state ----
#[async_trait]
trait State {
    async fn next(self: Box<Self>) -> Box<dyn State + Send>;
    fn status(&self) -> &'static str;
}

// ---- State: Disconnected ----
struct Disconnected;

#[async_trait]
impl State for Disconnected {
    async fn next(self: Box<Self>) -> Box<dyn State + Send> {
        println!("State: Disconnected. Attempting to connect...");
        sleep(Duration::from_secs(1)).await;
        Box::new(Connecting)
    }

    fn status(&self) -> &'static str {
        "Disconnected"
    }
}

// ---- State: Connecting ----
struct Connecting;

#[async_trait]
impl State for Connecting {
    async fn next(self: Box<Self>) -> Box<dyn State + Send> {
        println!("State: Connecting. Waiting for handshake...");
        sleep(Duration::from_secs(1)).await;
        println!("Connected!");
        Box::new(Connected)
    }

    fn status(&self) -> &'static str {
        "Connecting"
    }
}

// ---- State: Connected ----
struct Connected;

#[async_trait]
impl State for Connected {
    async fn next(self: Box<Self>) -> Box<dyn State + Send> {
        println!("State: Connected. Reading data...");
        sleep(Duration::from_secs(2)).await;
        println!("Connection lost.");
        Box::new(Disconnected)
    }

    fn status(&self) -> &'static str {
        "Connected"
    }
}

// ---- Context: Async State Machine Runner ----
struct Client {
    state: Box<dyn State + Send>,
}

impl Client {
    fn new() -> Self {
        Client {
            state: Box::new(Disconnected),
        }
    }

    async fn run(&mut self, cycles: usize) {
        for _ in 0..cycles {
            println!("Current state: {}", self.state.status());
            self.state = self.state.next().await;
        }
    }
}

// ---- Main Function ----
#[tokio::main]
async fn main() {
    let mut client = Client::new();
    client.run(5).await;
}
