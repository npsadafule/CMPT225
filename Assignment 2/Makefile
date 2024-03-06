# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Source files
SRCS = testOSLL.cpp testOSULL.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executables
TARGETS = testOSLL testOSULL

# Main target
all: $(TARGETS)

# Rule to build executables
$(TARGETS): %: %.o
	$(CXX) $(CXXFLAGS) -o $@ $<

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove generated files
clean:
	rm -f $(OBJS) $(TARGETS)
