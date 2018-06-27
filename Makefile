CC = gcc
CFLAGS = -Wall

all: bin build bin/exe

test: ./bin/test
	./bin/test

bin/exe: build/reit.o build/main.o  build/func.o test
	$(CC) $(CFLAGS) build/reit.o build/main.o build/func.o -o bin/exe

build/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o 

build/reit.o: src/reit.c
	$(CC) $(CFLAGS) -c src/reit.c -o build/reit.o 

build/func.o: src/func.c
	$(CC) $(CFLAGS) -c src/func.c -o build/func.o

bin/test: ./build/reit.o ./build/func.o ./build/main_test.o bin
	$(CC) $(CFLAGS) ./build/main_test.o ./build/func.o ./build/reit.o -o bin/test

./build/main_test.o: ./test/main.c ./thirdparty/ctest.h ./src/reithed.h ./src/func.h
	$(CC) $(CFLAGS) -I thirdparty -I src -c ./test/main.c -o ./build/main_test.o

bin:
	mkdir bin

build:
	mkdir build

.PHONY: clean
clean:
	rm -rf build/*.o