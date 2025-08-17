CXX = g++
CXXFLAGS = -Wall -std=c++17

SRC = main.cpp console_logger.cpp service.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@

clean:
	rm -f *.o $(TARGET)