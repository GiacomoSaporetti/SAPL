<<<<<<< HEAD
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "string_utilities.h"
#include "parser.h"
#include "database.h"

#define MAX_LINE_LENGTH 100
=======
#include "sapl.h"
>>>>>>> 9bf0b7e703409559e05b753f50ff9b0667dc7bf0


FILE* program;
char current_line[MAX_LINE_LENGTH];

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		printf("Invalid number of arguments\n");
		return 1;
	}
	program = fopen(argv[1], "r");
	if(program == NULL)
	{
		printf("No file named %s\n", argv[1]);
		return 1;
	}

	//Read all lines
	while(fgets(current_line, MAX_LINE_LENGTH, program))
	{
		RemoveComment(current_line);
		Parse(current_line);
	}

<<<<<<< HEAD
	int test = 12;
	printf("%d, %d\n", test, *(uint32_t) &test);
	//AddVariable(4, 4, "miavar", *  ((uint32_t *) &test));
=======
	Variable* v = GetVariable("variabilona");
	if(v != NULL) printf("%f, %x, %d, %x\n", v->data.FLOAT, v->data.FLOAT, v->data.INT, v->data.INT);

>>>>>>> 9bf0b7e703409559e05b753f50ff9b0667dc7bf0
	return 0;
}
