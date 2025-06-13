SRC = ${wildcard src/*.c}
OBJ = ${patsubst %.c,./obj/%.o,${SRC}}

all: sources
	@gcc ${wildcard ./obj/*.o} -o sapl

sources:
	@cd ./src/ && ${MAKE}

clean:
	@cd obj/ && rm -rf *.o

run: 
	@./sapl testprog.sapl

rebuild: clean all run