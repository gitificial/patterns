# Microservice example in Python

## Used concepts

| Concept                  | Where it Appears                        |
| ------------------------ | --------------------------------------- |
| **Service independence** | Two FastAPI apps in separate folders    |
| **HTTP communication**   | `httpx` call from order → user service  |
| **Decoupling**           | Services only interact via APIs         |
| **Scalability**          | Each service can scale separately       |
| **Error boundaries**     | Order service handles user API failures |

## Example: Request order service with curl
```
curl http://localhost:8002/orders/1
```

## Requirements
Install the requirements first:
```
pip install -r requirements.txt
```

