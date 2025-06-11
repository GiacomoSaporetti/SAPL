SRC = ${wildcard *.c}
OBJ = ${patsubst %.c,../obj/%.o,${SRC}}
INC = -I../include/
default: ${OBJ}
	@echo Compiled

../obj/%.o: %.c 
	@echo Compiling $<
	@echo ${INC}	
	@gcc -c $< ${INC} -o ../obj/${patsubst %.c,%.o,$<}

clean:
	@cd ../obj && rm -rf *.o
