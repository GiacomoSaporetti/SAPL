#include "parser.h"
#include "string_utilities.h"

void Parse(char*line)
{
	int sep=-1;
	
	//Assegnazione di variabile
	if(sep = FindPattern(line, "<--") > -1) AssignVariable(line, sep);
	
	//Scrittura di una variabile
//	if(sep = FindPattern(line, "write(") > -1) PrintSomething(line, sep);
	
}

void AssignVariable(char* line, int separator)
{
	// var1 <-- var2 + var3 / var5
	// var1 <-- 12
	
}
