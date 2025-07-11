#ifndef PARSER_H
#define PARSER_H
void Parse(char* line);

void AssignVariable(char* line, int separator);

void PrintSomething(char* line, int separator);

union var_data EvaluateExpression(char* line);
#endif
