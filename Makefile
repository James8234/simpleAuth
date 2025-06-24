CFLAGS = -Wall -Werror -Wpedantic -std=c++20
CC = g++ -MMD -MP

OBJECTS = main.o test/test.o

LIBS = -lssl -lcrypto

default: run

run: $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

main.o: header.h test/test.h

test/test.o:

.PHONY: clean
clean:
	rm -f $(OBJECTS)
