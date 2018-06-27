CC = gcc
CFLAGS = -Wall

all: bin build build/src/ bin/exe

test: ./bin/test
	./bin/test

bin/exe: build/src/reit.o build/src/main.o  build/src/func.o test
	$(CC) $(CFLAGS) build/src/reit.o build/src/main.o build/src/func.o -o bin/exe

build/src/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o build/src/main.o 

build/src/reit.o: src/reit.c
	$(CC) $(CFLAGS) -c src/reit.c -o build/src/reit.o 

build/src/func.o: src/func.c
	$(CC) $(CFLAGS) -c src/func.c -o build/src/func.o

bin/test: ./build/src/reit.o ./build/src/func.o ./build/src/main_test.o bin
	$(CC) $(CFLAGS) ./build/src/main_test.o ./build/src/func.o ./build/src/reit.o -o bin/test

./build/src/main_test.o: ./test/main.c ./thirdparty/ctest.h ./src/reithed.h ./src/func.h
	$(CC) $(CFLAGS) -I thirdparty -I src -c ./test/main.c -o ./build/src/main_test.o

bin:
	mkdir bin

build:
	mkdir build

build/src/:
	mkdir build/src

.PHONY: clean
clean:
	rm -rf build/src/*.o
	rm -rf build/src