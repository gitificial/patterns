# Watchdog Triggering

A watchdog timer is a countdown timer that resets the system if it isn't periodically refreshed ("kicked" or "fed"). It's used to detect software faults.

- watchdog_kick(): Refresh timer to avoid reset
- watchdog_check(): Check if time exceeded
- simulate_hang: Intentionally skip a kick
- watchdog monitor: loop that triggers a system reset if not refreshed in time