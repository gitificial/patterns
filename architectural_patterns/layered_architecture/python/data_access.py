# Data access layer

class UserRepository:
    def __init__(self):
        self._users = {}  # simple in-memory "database"

    def save_user(self, username, email):
        if username in self._users:
            raise ValueError("User already exists")
        self._users[username] = {"email": email}
        print(f"[DAL] User '{username}' saved")

    def get_user(self, username):
        return self._users.get(username)
