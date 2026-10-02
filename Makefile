CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = program
SRCS = $(wildcard *.cpp)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

format:
	clang-format -i *.cpp *.h

clean:
	rm -rf $(TARGET)

.PHONY: format clean
