#include <stdio.h>
#include <string.h>

#define MAX_USERS 2

typedef struct User User;
typedef struct Mediator Mediator;

struct Mediator {
    User *users[MAX_USERS];
    int user_count;

    void (*register_user)(Mediator *self, User *user);
    void (*send_message)(Mediator *self, const char *message, User *from, User *to);
};

struct User {
    char name[20];
    Mediator *mediator;

    void (*send)(User *self, const char *message, User *to);
    void (*receive)(User *self, const char *message, User *from);
};

// Forward declarations
void mediator_register_user(Mediator *self, User *user);
void mediator_send_message(Mediator *self, const char *message, User *from, User *to);

void user_send(User *self, const char *message, User *to);
void user_receive(User *self, const char *message, User *from);

// Mediator constructor
Mediator create_mediator() {
    Mediator m = { .user_count = 0, .register_user = mediator_register_user, .send_message = mediator_send_message };
    return m;
}

void mediator_register_user(Mediator *self, User *user) {
    if (self->user_count < MAX_USERS) {
        self->users[self->user_count++] = user;
        printf("[Mediator] Registered user: %s\n", user->name);
    }
}

void mediator_send_message(Mediator *self, const char *message, User *from, User *to) {
    printf("[Mediator] %s sends message to %s\n", from->name, to->name);
    to->receive(to, message, from);
}

// User constructor
User create_user(const char *name, Mediator *mediator) {
    User u;
    strncpy(u.name, name, sizeof(u.name));
    u.mediator = mediator;
    u.send = user_send;
    u.receive = user_receive;
    return u;
}

void user_send(User *self, const char *message, User *to) {
    self->mediator->send_message(self->mediator, message, self, to);
}

void user_receive(User *self, const char *message, User *from) {
    printf("[%s] received message from %s: %s\n", self->name, from->name, message);
}

int main() {
    Mediator mediator = create_mediator();

    User alice = create_user("Alice", &mediator);
    User bob = create_user("Bob", &mediator);

    mediator.register_user(&mediator, &alice);
    mediator.register_user(&mediator, &bob);

    alice.send(&alice, "Hi Bob!", &bob);
    bob.send(&bob, "Hello Alice!", &alice);

    return 0;
}
