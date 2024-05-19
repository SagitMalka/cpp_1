CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

EXEC = TestCounter

SRCS = Algorithms.cpp Graph.cpp Test.cpp TestCounter.cpp

HEADERS = Algorithms.hpp Graph.hpp doctest.h

OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)


valgrind: $(EXEC)
	valgrind $(VALGRIND_FLAGS) ./$(EXEC)

.PHONY: all clean valgrind

# Compiler and flags
# CXX = g++
# CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

# # Valgrind flags
# VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

# # Executable names
# EXEC = TestCounter
# TEST_EXEC = TestExecutable

# # Source files
# SRCS = Algorithms.cpp Graph.cpp Test.cpp TestCounter.cpp

# # Header files (for dependency generation)
# HEADERS = Algorithms.hpp Graph.hpp doctest.h

# # Object files
# OBJS = $(SRCS:.cpp=.o)

# # Default target
# all: $(EXEC)

# # Rule to create the main executable
# $(EXEC): $(OBJS)
# 	$(CXX) $(CXXFLAGS) -o $@ $^

# # Rule to create the test executable
# $(TEST_EXEC): Algorithms.o Graph.o Test.o
# 	$(CXX) $(CXXFLAGS) -o $@ $^

# # Pattern rule to create object files from .cpp files
# %.o: %.cpp $(HEADERS)
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# # Clean up build artifacts
# clean:
# 	rm -f $(OBJS) $(EXEC) $(TEST_EXEC)

# # Run valgrind with the main executable
# valgrind: $(EXEC)
# 	valgrind $(VALGRIND_FLAGS) ./$(EXEC)

# # Run valgrind with the test executable
# valgrind-test: $(TEST_EXEC)
# 	valgrind $(VALGRIND_FLAGS) ./$(TEST_EXEC)

# # Phony targets
# .PHONY: all clean valgrind valgrind-test
