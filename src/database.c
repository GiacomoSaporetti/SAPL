<<<<<<< HEAD
#include "database.h"
#include "string_utilities.h"
#include "stdlib.h"

struct Node* VARIABLE_NODES;
=======
#include "sapl.h"

struct Node VARIABLE_START = {NULL, NULL};
struct Node* VARIABLE_NODES = &VARIABLE_START;
>>>>>>> 9bf0b7e703409559e05b753f50ff9b0667dc7bf0

struct Node* FindLastNode(struct Node* first_node)
{
	struct Node* current_node = first_node;
	while(current_node->next != NULL)
<<<<<<< HEAD
	{
		current_node = current_node->next;
	}
=======
	{current_node = current_node->next;}
>>>>>>> 9bf0b7e703409559e05b753f50ff9b0667dc7bf0

	return current_node;
}

<<<<<<< HEAD
void AddVariable(int type, int bytes, char* identifier, uint32_t data)
{
	struct Variable* new_var = (struct Variable*) malloc(sizeof(struct Variable));
	new_var->type = type;
	new_var->bytes = bytes;
=======
void AddVariable(int type, char* identifier, union var_data data)
{
	//Check that no other variable exist under the same identifier
	Variable* existence_check = GetVariable(identifier);
	if(existence_check != NULL)
	{
		existence_check->type = type;
		existence_check->data = data;
		return;
	}

	//If it doesn't exist append it to the linked list

	struct Variable* new_var = (struct Variable*) malloc(sizeof(struct Variable));

	new_var->type = type;
>>>>>>> 9bf0b7e703409559e05b753f50ff9b0667dc7bf0
	CopyString(new_var->identifier, identifier);
	new_var->data = data;

	AddNode(FindLastNode(VARIABLE_NODES), new_var);
}


struct Node* AddNode(struct Node* last_node, void* data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node*));

	if(new_node == NULL) return NULL;

	last_node->next = new_node;

	new_node->next = NULL;
	new_node->data = data;

	return new_node;
}

struct Variable* GetVariable(char* identifier)
{
	struct Node* current_node = VARIABLE_NODES;

	
	while((current_node = current_node->next) != NULL)
	{
		struct Variable* current_var = (struct Variable*) current_node->data;
		if(current_var == NULL) continue;
		if(CompareString(current_var->identifier, identifier)) return (struct Variable*) current_node->data;
	}

	return NULL;
}

