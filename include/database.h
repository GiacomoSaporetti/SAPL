#ifndef DATABASE_H
#define DATABASE_H
#include <stdint.h>

union var_data
{
	int INT;
	float FLOAT;
};

typedef struct Node
{
	struct Node* next;
	void* data;
} Node;

typedef struct Variable
{
	int type;
	char identifier[50];
	union var_data data;
} Variable;

enum v_type
{
	INT,
	FLOAT,
};

struct Node* AddNode(struct Node* last_node, void* data);

void AddVariable(int type, char* identifier, union var_data data);

struct Variable* GetVariable(char* identifier); 
#endif
