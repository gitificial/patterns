CFLAGS=-Iunity -Isrc -Itest

SRC=test/test_controller.c test/test_sensor_stub.c unity/unity.c

all:
	gcc $(CFLAGS) $(SRC) -o run_tests
	./run_tests

clean:
	rm -f run_tests