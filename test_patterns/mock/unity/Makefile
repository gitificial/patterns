# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iunity -Isrc -Itest

# Source files
SRC = \
    unity/unity.c \
    src/controller.c \
    test/mock_fan.c \
    test/test_controller.c

all:
	gcc $(CFLAGS) $(SRC) -o run_tests
	./run_tests

clean:
	rm -f run_tests