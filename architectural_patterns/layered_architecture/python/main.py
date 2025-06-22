# Presentation layer

from data_access import UserRepository
from business_logic import UserService
from application import UserApplication

def main():
    user_repo = UserRepository()
    user_service = UserService(user_repo)
    app = UserApplication(user_service)

    # Simulate UI interaction
    print("Registering user 'alice'")
    app.process_registration("alice", "alice@example.com")

    print("Registering 'alice' again")
    app.process_registration("alice", "alice@example.com")  # should fail

if __name__ == "__main__":
    main()
