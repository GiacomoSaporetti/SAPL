#ifndef DATABASE_H
#define DATABASE_H
#include <stdint.h>

typedef struct Node
{
	struct Node* next;
	void* data;
};

typedef struct Variable
{
	int type;
	int bytes;
	char identifier[50];
	uint32_t data;
};

struct Node* AddNode(struct Node* last_node, void* data);

void AddVariable(int type, int bytes, char* identifier, uint32_t data);

struct Variable* GetVariable(char* identifier); 
#endif
