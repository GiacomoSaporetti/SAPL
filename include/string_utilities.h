#ifndef STRING_UTILS_H
#define STRING_UTILS_H

int FindPattern(char* line, char* pattern);
int FindChar(char* line, char pattern);

void RemoveComment(char* line);

void CopyString(char* dst, char* src);

int CompareString(char* str1, char* str2);
<<<<<<< HEAD
=======

int StringLenght(char* str);

char* Substring(char*str, int start, int stop);

union var_data StringToBits(char* str);

char* RemoveChar(char* str, char c);
>>>>>>> 9bf0b7e703409559e05b753f50ff9b0667dc7bf0
#endif
