#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 100


FILE* program;
char current_line[MAX_LINE_LENGTH];

void RemoveComment(char* line)
{
	int i=-1;
	while(line[++i] != '\0')
	{
		if(line[i] == '#')
		{
			line[i] = '\0';
			break;
		}
	}
}

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
		printf("%s", current_line);
	}
	return 0;
}
