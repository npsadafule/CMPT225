# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Source files
SRCS = DQarraytest.cpp DQtest.cpp DQtest1.cpp
DEQUE_HEADER = Deque.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executables
TARGETS = DQarraytest DQtest DQtest1

# Main target
all: $(TARGETS)

# Rule to build executables
$(TARGETS): %: %.o
	$(CXX) $(CXXFLAGS) -o $@ $<

# Rule to build object files
%.o: %.cpp $(DEQUE_HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove generated files
clean:
	rm -f $(OBJS) $(TARGETS)
