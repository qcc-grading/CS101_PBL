  # the compiler: gcc for C program, define as g++ for C++
CXX = g++

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
CXXFLAGS = -g -Wall -std=c++11

  # the build target executable:

all: $(TARGET)

$(TARGET): $(TARGET).cc
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cc

clean:
	$(RM) $(TARGET)