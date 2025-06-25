# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iunity -I. -Itest

# Source files
SRC = unity/unity.c eeprom_fake.c test/test_eeprom.c

all:
	gcc $(CFLAGS) $(SRC) -o run_tests
	./run_tests

clean:
	rm -f run_tests
