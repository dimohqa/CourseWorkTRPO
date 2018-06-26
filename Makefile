OBJ = 
flags = -Wall -Werror -std=c99

.PHONY: clean open

./bin/go: ./build/main.o ./build/func.o ./build/reit.o bin test
	gcc $(flags) -o ./bin/go  ./build/main.o ./build/func.o ./build/reit.o

./build/main.o: ./src/main.c ./src/func.h build
	gcc $(flags) -o build/main.o -c src/main.c

./build/func.o: ./src/func.c ./src/func.h build
	gcc $(flags) -o ./build/func.o -c ./src/func.c

./build/reit.o: ./src/reit.c ./src/reithed.h build
	gcc $(flags) -o ./build/reit.o -c ./src/reit.c

build:
	mkdir build
bin:
	mkdir bin
clean:
	rm -rf build bin
open:
	./bin/go