#include "sapl.h"

void Parse(char*line)
{
	float res=0;
	//Assegnazione di variabile
	if(FindPattern(line, "=") > -1) res = EvaluateExpression(RemoveChar(line, ' ')).FLOAT;
	
	printf("%f\n", res);
	//Scrittura di una variabile
//	if(sep = FindPattern(line, "write(") > -1) PrintSomething(line, sep);
	
}

void AssignVariable(char* line, int separator)
{
	// var1 <-- var2 + var3 / var5
	// var1 <-- 12
	char* identifier = RemoveChar(Substring(line, 0, separator), ' ');
	union var_data bits = StringToBits(Substring(line, separator+1, -1));
	AddVariable(INT, identifier, bits);
}

union var_data EvaluateExpression(char* line)
{
	int op_type = -1;
	uint32_t pls = FindChar(line, '+');
	uint32_t mns = FindChar(line, '-');
	uint32_t mlt = FindChar(line, '*');
	uint32_t dvd = FindChar(line, '/');
	
	printf("%d, %d, %d\n", mns, mns==4294967295, mns==-1);

	if(pls == -1 && mns == -1 && mlt == -1 && dvd == -1)
		return StringToBits(line);

	uint32_t operations_left = pls>0 + mns>0 + mlt>0 + dvd>0;  

	uint32_t first_op = pls;
	op_type = 0;
	if(mns<first_op)
	{
		first_op = mns;
		op_type = 1;
	}
	if(mlt<first_op)
	{
		first_op = mlt;
		op_type = 2;
	}
	if(dvd<first_op)
	{
		first_op = dvd;
		op_type = 3;
	}
	 
	if(operations_left == 1)
	{
		float op1 = StringToBits(Substring(line, 0, first_op)).FLOAT;
		float op2 = StringToBits(Substring(line, first_op+1, -1)).FLOAT;
		float res;
		if(pls>0)
			res = op1+op2;
		if(mns>0)
			res = op1-op2;
		if(mlt>0)
			res = op1*op2;
		if(dvd>0)
			res = op1/op2;
		return TO_BITS(res);		
	}



	union var_data res;

	return res;
	//int first_op = plus;


}