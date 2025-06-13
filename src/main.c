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

	float test1 = 12.345;
	float test2 = 4.444;
	int test3 = 1;
	int test4 = 182;
	//printf("%d, %d\n", test, *(uint32_t*) &test);
	AddVariable(FLOAT, "miavar", TO_BITS(test1));
	AddVariable(FLOAT, "miavar", TO_BITS(test2));
	AddVariable(INT, "miavar", TO_BITS(test3));
	AddVariable(INT, "miavar2", TO_BITS(test2));
	Variable* v;
	v = GetVariable("miavar");
	printf("%f, %d\n",v->data.FLOAT, v->data.INT);
	v = GetVariable("miavar2");
	printf("%f, %d\n",v->data.FLOAT, v->data.INT);
	return 0;
}
