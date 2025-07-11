<<<<<<< HEAD
#include "parser.h"
#include "string_utilities.h"
=======
#include "sapl.h"
>>>>>>> 9bf0b7e703409559e05b753f50ff9b0667dc7bf0

void Parse(char*line)
{
	int sep=-1;
	
	//Assegnazione di variabile
<<<<<<< HEAD
	if(sep = FindPattern(line, "<--") > -1) AssignVariable(line, sep);
=======
	if((sep = FindPattern(line, "<--")) > -1) AssignVariable(line, sep);
>>>>>>> 9bf0b7e703409559e05b753f50ff9b0667dc7bf0
	
	//Scrittura di una variabile
//	if(sep = FindPattern(line, "write(") > -1) PrintSomething(line, sep);
	
}

void AssignVariable(char* line, int separator)
{
	// var1 <-- var2 + var3 / var5
	// var1 <-- 12
<<<<<<< HEAD
	
=======
	char* identifier = RemoveChar(Substring(line, 0, separator), ' ');
	union var_data bits = StringToBits(Substring(line, separator+3, -1));
	AddVariable(INT, identifier, bits);
>>>>>>> 9bf0b7e703409559e05b753f50ff9b0667dc7bf0
}
