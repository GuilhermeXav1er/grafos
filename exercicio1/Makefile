CC = gcc
programa = main
tests-directory= ./test_cases

all: main.c ./lib/MatrizAdj.c ./lib/MatrizAdj.h
	$(CC) -o $(programa) ./main.c ./lib/MatrizAdj.c

clean:
	rm *.o $(programa)

run:
	$(CC) -o $(programa) ./main.c ./lib/MatrizAdj.c
	./$(programa) < $(tests-directory)/1graph.txt