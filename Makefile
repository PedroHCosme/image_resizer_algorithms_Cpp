# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iinclude -O2

# Linker flags
LDFLAGS = -lX11

# Target executable
TARGET = build/ex

# Source files
SOURCES = src/main.cpp src/resize_nearest_neighbour.cpp src/resize_bilinear.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS := $(patsubst src/%,build/%,$(OBJECTS))

# Default target
all: create_build_dir $(TARGET)

# Create build directory if it does not exist
create_build_dir:
	mkdir -p build

# Build target
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compile source files into object files
build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f build/*.o $(TARGET)

# Phony targets
.PHONY: all clean create_build_dir
