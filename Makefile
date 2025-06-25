#CFLAGS = -Wall -Werror -Wpedantic -std=c++20
#CC = g++ -MMD -MP

INCLUDES = -Iinclude
C = g++
LIBS = -lssl -lcrypto

CFLAGS = -std=c++20 -Wall -Werror -Wpedantic $(INCLUDES)
#OBJECTS = main.o test/test.o utils/bloomFilter/bloomFilter.o utils/Tools/fileLockingTools.o
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = bin/project


all: $(TARGET)

$(TARGET): $(OBJ)
	$(C) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

src/%.o: src/%.cpp
	$(C) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)

