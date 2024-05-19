# # Define the compiler
# CXX = g++

# # Define the compiler flags
# CXXFLAGS = -Wall -Wextra -std=c++11

# # Define the target executable
# TARGET = test

# # Define the source files
# SRCS = Test.cpp TestCounter.cpp Algorithms.cpp Graph.cpp

# # Define the object files
# OBJS = $(SRCS:.cpp=.o)

# # Rule to link the object files into the final executable
# $(TARGET): $(OBJS)
# 	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# # Rule to compile the source files into object files
# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# # Clean rule to remove generated files
# clean:
# 	rm -f $(OBJS) $(TARGET)

# # Phony targets
# .PHONY: clean

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Executable name
EXEC = TestCounter

# Source files
SRCS = Algorithms.cpp Graph.cpp Test.cpp TestCounter.cpp

# Header files (for dependency generation)
HEADERS = Algorithms.hpp Graph.hpp doctest.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(EXEC)

# Rule to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Pattern rule to create object files from .cpp files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean
