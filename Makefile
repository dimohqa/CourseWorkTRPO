CC = gcc
CFLAGS = -Wall

all: bin build build/src/ bin/exe

bin/exe: build/src/reit.o build/src/main.o  build/src/func.o 
	$(CC) $(CFLAGS) build/src/reit.o build/src/main.o build/src/func.o -o bin/exe

build/src/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o build/src/main.o 

build/src/reit.o: src/reit.c
	$(CC) $(CFLAGS) -c src/reit.c -o build/src/reit.o 

build/src/func.o: src/func.c
	$(CC) $(CFLAGS) -c src/func.c -o build/src/func.o

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