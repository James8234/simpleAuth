CFLAGS = -Wall -Werror -Wpedantic -std=c++20
CC = g++ -MMD -MP

OBJECTS = main.o test/test.o utils/bloomFilter/bloomFilter.o utils/Tools/fileLockingTools.o

LIBS = -lssl -lcrypto

default: run

run: $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

main.o: header.h test/test.h utils/bloomFilter/bloomFilter.h

test/test.o:

utils/bloomFilter/bloomFilter.o: utils/bloomFilter/bloomFilter.h utils/Tools/fileLockingTools.h

.PHONY: clean
clean:
	rm -f $(OBJECTS)
