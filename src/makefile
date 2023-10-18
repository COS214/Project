CXX = g++
SRC_DIR = .
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(SRC_DIR)/%.o, $(SRC_FILES))

TARGET = main

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -g   # Added '-g' flag for debugging symbols

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

debug: $(TARGET)
	gdb $(TARGET)   # Run gdb with the compiled program

clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)
