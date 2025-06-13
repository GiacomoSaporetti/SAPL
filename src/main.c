#include "sapl.h"


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

	Variable* v = GetVariable("variabilona");
	if(v != NULL) printf("%f, %x, %d, %x\n", v->data.FLOAT, v->data.FLOAT, v->data.INT, v->data.INT);

	return 0;
}
