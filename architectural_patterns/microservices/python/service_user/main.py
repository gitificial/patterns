from fastapi import FastAPI

app = FastAPI()

fake_users = {
    1: {"id": 1, "name": "Alice"},
    2: {"id": 2, "name": "Bob"},
}

@app.get("/users/{user_id}")
def get_user(user_id: int):
    user = fake_users.get(user_id)
    if user:
        return user
    return {"error": "User not found"}
