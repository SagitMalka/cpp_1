# 209294768 sagitmalka10@gmail.com
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
