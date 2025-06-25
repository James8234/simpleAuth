INCLUDES = -Iinclude
C = g++
LIBS = -lssl -lcrypto

CFLAGS = -std=c++20 -Wall -Werror -Wpedantic $(INCLUDES)
# wildcard grab all .cpp files in the src/ folder adn assign them to SRC
SRC = $(wildcard src/*.cpp)
# Converts each .cpp into its .o object file name
OBJ = $(SRC:.cpp=.o)
# Final output binary
TARGET = bin/project

#Build rules
all: $(TARGET)

# Links project into executable
$(TARGET): $(OBJ)
	$(C) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)
#Compile individual cpp files into .o
src/%.o: src/%.cpp
	$(C) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)

