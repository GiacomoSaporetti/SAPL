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
			if(line[k] == '\0') return -1;
		}
		if(pattern[j] == '\0')
			return i;
	}
	return -1;
}
