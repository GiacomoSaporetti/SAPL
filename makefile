SRC = ${wildcard src/*.c}
OBJ = ${patsubst %.c,./obj/%.o,${SRC}}
LINKS = -lm

all: sources
	@gcc ${wildcard ./obj/*.o} -o sapl ${LINKS}

sources:
	@cd ./src/ && ${MAKE}

clean:
	@cd obj/ && rm -rf *.o

run: 
	@./sapl testprog.sapl

rebuild: clean all run