#ifndef DATABASE_H
#define DATABASE_H
#include <stdint.h>

<<<<<<< HEAD
=======
union var_data
{
	int INT;
	float FLOAT;
	uint32_t BITS;
};

>>>>>>> 9bf0b7e703409559e05b753f50ff9b0667dc7bf0
typedef struct Node
{
	struct Node* next;
	void* data;
<<<<<<< HEAD
};
=======
} Node;
>>>>>>> 9bf0b7e703409559e05b753f50ff9b0667dc7bf0

typedef struct Variable
{
	int type;
<<<<<<< HEAD
	int bytes;
	char identifier[50];
	uint32_t data;
=======
	char identifier[50];
	union var_data data;
} Variable;

enum v_type
{
	INT,
	FLOAT,
>>>>>>> 9bf0b7e703409559e05b753f50ff9b0667dc7bf0
};

struct Node* AddNode(struct Node* last_node, void* data);

<<<<<<< HEAD
void AddVariable(int type, int bytes, char* identifier, uint32_t data);
=======
void AddVariable(int type, char* identifier, union var_data data);
>>>>>>> 9bf0b7e703409559e05b753f50ff9b0667dc7bf0

struct Variable* GetVariable(char* identifier); 
#endif
