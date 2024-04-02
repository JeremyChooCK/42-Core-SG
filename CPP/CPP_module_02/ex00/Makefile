# Define the compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -g

# Name of the output binary
TARGET = main

# Source files
SOURCES = main.cpp \
		Fixed.cpp \

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Build rule
all: $(TARGET)

# Link the target with object files
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Rule for object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean rule for object files
clean:
	rm -f $(OBJECTS)

# Full Clean (fclean) rule for both object files and the executable
fclean: clean
	rm -f $(TARGET)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re