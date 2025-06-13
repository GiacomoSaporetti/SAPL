#include "sapl.h"

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
		if(pattern[j] == '\0') return i;
	}
	return -1;
}

int FindChar(char* line, char pattern)
{
	int i=-1;
	while(line[++i]!='\0')
	{
		if(line[i] != pattern)
			continue;
		
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


int StringLenght(char* str)
{
	if(str == NULL) return 0;

	int i=-1;
	while(str[++i] != '\0'){;}

	return i;
}

char* Substring(char*str, int start, int stop)
{
	int len= StringLenght(str);
	if(start > len) return NULL;

	int res_len = stop>start? stop-start : len-start;

	char * res = (char *) malloc(sizeof(char)*res_len+1);

	for(int i=0; i<res_len; i++)
		res[i] = str[start+i];
	res[res_len] = '\0';

	return res;
}

char* RemoveChar(char* str, char c)
{
	int len = StringLenght(str);
	char* res = (char*) malloc(len*sizeof(char));

	int current_idx = 0;
	for(int i=0; i<len; i++)
	{
		if(str[i] == c) continue;
		res[current_idx++] = str[i];		
	}
	
	return res;
}


union var_data StringToBits(char* str)
{
	str = RemoveChar(str, ' ');

	//Verify if its a float
	int point = FindChar(str, '.');
	int len = StringLenght(str);
	if(point > -1)
	{
		//It's a float
		float res=0;
		for(int i=0; i<len; i++)
		{
			if(str[i] == '.') continue;
			res = res*10;
			if(str[i] < 48 || str[i] > 57)	break;

			res += (str[i] - 48);
		}
		res = res/powf(10,len - point-1);
		return TO_BITS(res);
	}
	else
	{
		//It's an int
		long int res=0;
		for(int i=0; i<len; i++)
		{
			if(str[i] < 48 || str[i] > 57)	break; 

			res = res*10;
			res += (str[i] - 48);
			printf("i: %ld, res: %ld (%x), char: %c\n", i, res, res, str[i]);
		}
		int r = (int) res;
		printf("r: %d (%x), res: %ld (%lx)\n", r, r, res, res);
		return TO_BITS(r);
	}
}