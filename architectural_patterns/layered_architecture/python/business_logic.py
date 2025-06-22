# Business logic layer

class UserService:
    def __init__(self, user_repository):
        self.user_repo = user_repository

    def register_user(self, username, email):
        if not username or not email:
            raise ValueError("Username and email are required")

        if self.user_repo.get_user(username):
            raise ValueError("Username already taken")

        self.user_repo.save_user(username, email)
        print(f"[BLL] Registered user '{username}'")
