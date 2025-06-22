from fastapi import FastAPI
import httpx

app = FastAPI()

@app.get("/orders/{user_id}")
async def get_orders_for_user(user_id: int):
    async with httpx.AsyncClient() as client:
        response = await client.get(f"http://localhost:8001/users/{user_id}")
        if response.status_code != 200:
            return {"error": "User service unavailable or user not found"}

        user = response.json()
        # Simulate order data
        orders = [
            {"id": 1, "item": "Laptop"},
            {"id": 2, "item": "Headphones"}
        ]
        return {"user": user, "orders": orders}
