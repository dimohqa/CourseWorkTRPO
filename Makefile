flags = -Wall

.PHONY: clean open

./bin/go: ./build/main.o ./build/func.o ./build/reit.o bin test
	gcc $(flags) -o ./bin/go ./build/func.o ./build/reit.o
