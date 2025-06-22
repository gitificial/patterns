class ChatRoom:
    def __init__(self):
        self.users = []

    def register(self, user):
        self.users.append(user)
        user.chatroom = self
        print(f"[ChatRoom] {user.name} has entered the chat.")

    def send(self, message, from_user, to_user=None):
        if to_user:
            print(f"[Private] {from_user.name} -> {to_user.name}: {message}")
            to_user.receive(message, from_user)
        else:
            print(f"[Broadcast] {from_user.name}: {message}")
            for user in self.users:
                if user != from_user:
                    user.receive(message, from_user)


class User:
    def __init__(self, name):
        self.name = name
        self.chatroom = None

    def send(self, message, to_user=None):
        if self.chatroom:
            self.chatroom.send(message, self, to_user)
        else:
            print(f"{self.name} is not in a chatroom.")

    def receive(self, message, from_user):
        print(f"{self.name} received from {from_user.name}: {message}")


# --- Usage Example ---

if __name__ == "__main__":
    chatroom = ChatRoom()

    alice = User("Alice")
    bob = User("Bob")
    charlie = User("Charlie")

    chatroom.register(alice)
    chatroom.register(bob)
    chatroom.register(charlie)

    alice.send("Hello everyone!")  # Broadcast
    bob.send("Hi Alice!", to_user=alice)  # Private
    charlie.send("Good morning!")  # Broadcast
