# Proxy Pattern

## Example: Proxy for a Temperature Sensor

Scenario:
- The real subject is a hardware temperature sensor.
- The proxy provides controlled access to the sensor by caching the last read value and avoiding redundant I2C communication.
- The application interacts with the proxy instead of directly communicating with the sensor.

The Proxy Pattern is a structural design pattern where a class (the proxy) acts as an intermediary to control access to another object (the real subject). This is useful for tasks like lazy initialization, access control, logging, or caching.

1. Real Subject (temp_sensor.c):

- Implements the actual hardware interactions to read temperature from the sensor.

2. Proxy (temp_sensor_proxy.c):

- Adds a layer of caching to avoid frequent I2C communication.
- Only fetches fresh data from the real subject if the cache is expired.

3. Application (main.c):

- Uses the proxy to get the temperature without worrying about caching or low-level details.

4. Caching Logic:

- The proxy stores the last read temperature and timestamp.
- If the cache is still valid (based on CACHE_TIMEOUT_SECONDS), it returns the cached value.

## Benefits of the Proxy Pattern
1. Lazy Initialization:

- The proxy can delay access to the real subject until it’s actually needed.

2. Caching:

- Reduces redundant hardware accesses, improving performance and power efficiency.

3. Access Control:

- The proxy can restrict or validate access to the real subject.

4. Logging/Monitoring:

The proxy can log requests to the real subject for debugging or auditing.

5. Modularity:

The application doesn’t need to be modified to add caching or other enhancements.