#ifndef STRING_UTILS_H
#define STRING_UTILS_H

int FindPattern(char* line, char* pattern);
int FindChar(char* line, char pattern);

void RemoveComment(char* line);

void CopyString(char* dst, char* src);

int CompareString(char* str1, char* str2);

int StringLenght(char* str);

char* Substring(char*str, int start, int stop);

union var_data StringToBits(char* str);

char* RemoveChar(char* str, char c);
#endif
