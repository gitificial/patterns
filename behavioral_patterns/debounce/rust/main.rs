use tokio::time::{sleep, Duration, Instant};

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum InputState {
    Low,
    High,
}

/// Debouncer for a digital input
struct Debouncer {
    state: InputState,
    last_transition: Instant,
    debounce_duration: Duration,
}

impl Debouncer {
    fn new(initial: InputState, debounce_duration: Duration) -> Self {
        Debouncer {
            state: initial,
            last_transition: Instant::now(),
            debounce_duration,
        }
    }

    /// Call this whenever a raw input is detected
    async fn update(&mut self, raw_state: InputState) -> Option<InputState> {
        let now = Instant::now();

        // If the input has changed
        if raw_state != self.state {
            if now.duration_since(self.last_transition) >= self.debounce_duration {
                self.state = raw_state;
                self.last_transition = now;
                return Some(self.state); // Report valid state change
            }
        } else {
            // Reset the transition timer if stable
            self.last_transition = now;
        }

        None // No valid change yet
    }
}

// Simulated bouncing button press input
async fn simulate_bouncing_input() -> Vec<(Duration, InputState)> {
    vec![
        (Duration::from_millis(0), InputState::High),
        (Duration::from_millis(10), InputState::Low),
        (Duration::from_millis(20), InputState::High),
        (Duration::from_millis(40), InputState::Low),
        (Duration::from_millis(60), InputState::High),
        (Duration::from_millis(150), InputState::Low),
    ]
}

#[tokio::main]
async fn main() {
    let debounce_time = Duration::from_millis(50);
    let mut debouncer = Debouncer::new(InputState::Low, debounce_time);

    let input_sequence = simulate_bouncing_input().await;

    let start = Instant::now();
    for (delay, raw_state) in input_sequence {
        sleep(delay).await;

        if let Some(valid_state) = debouncer.update(raw_state).await {
            println!(
                "[{:>5?}] Debounced state: {:?}",
                Instant::now().duration_since(start),
                valid_state
            );
        } else {
            println!(
                "[{:>5?}] Ignored bouncing: {:?}",
                Instant::now().duration_since(start),
                raw_state
            );
        }
    }
}

