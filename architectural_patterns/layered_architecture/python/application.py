# Application layer

class UserApplication:
    def __init__(self, user_service):
        self.user_service = user_service

    def process_registration(self, username, email):
        try:
            self.user_service.register_user(username, email)
            return True
        except ValueError as e:
            print(f"[App] Registration failed: {e}")
            return False
