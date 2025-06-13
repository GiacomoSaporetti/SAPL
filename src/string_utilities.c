#include <stdlib.h>
#include "string_utilities.h"

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

int FindPattern(char*line, char*pattern)
{
	if(pattern == NULL) return -1;
	if(pattern[0] == '\0') return -1;

	int i=-1;
	while(line[++i]!='\0')
	{
		if(line[i] != pattern[0])
			continue;
		
		int k=i, j=0;

		while(line[++k] == pattern[++j])
		{
			if(line[k] == '\0') return i;
		}
		if(pattern[j] == '\0')
			return i;
	}
	return -1;
}


void CopyString(char* dst, char* src)
{
	int i=-1;
	do
	{
		i++;
		dst[i] = src[i]; 
	}
	while(src[i] != '\0');
}


int CompareString(char* str1, char* str2)
{
	int i=-1;
	while(str1[++i] != '\0' && str2[i] != '\0')
	{
		if(str1[i] != str2[i]) return 0;
	}

	if(str1[i] == str2[i]) return 1;

	return 0;
}
