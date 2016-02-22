// pettree.h -- interface for a binary search tree linked list data type

#ifndef PETTREE_H_
#define PETTREE_H_ 1

#include <stdbool.h>

#define STRLEN 30

// Type definitions

typedef struct pet
{
	char type[STRLEN];
	char name[STRLEN];
	struct pet * next;
} Pet;

typedef Pet * List;

typedef struct node {
	char name[STRLEN];
	List head;
	struct node * left;
	struct node * right;
} Node;

typedef Node * Tree;

// Operations

// Operation: Initialize a Tree
// Preconditions: ptree points to an unitialized Tree
// Postconditions: ptree points to an initialized Tree
Tree * InitializeTree(Tree * ptree);


// Return true if Tree pointed to by ptree is empty, otherwise
// return false
bool TreeIsEmpty(const Tree * ptree);

// Return true if Tree pointed to by ptree is full, otherwise
// return false
bool TreeIsFull(const Tree * ptree);

// Add Pet item with given name and type to Tree pointed
// to by ptree
// Return: true if operation succeeds, otherwise false
bool AddPet(Pet * ppet, Tree * ptree);

// Find and remove the Node corresponding the to string word
// in the Tree pointed to by ptree if it exists.
// Return: true if the Node corresponding to word is found
// and deleted, otherwise false
bool DeletePet(Pet * ppet, Tree * ptree);

// Search for Node corresponding to string name in Tree
// pointed to by ptree.
// Return: true if word is found in Tree, otherwise false
bool InTree(Pet * ppet, const Tree * ptree);

int TreeItemCount(Tree tree);

// Visit each Node in Tree pointed to by ptree, calling
// function pointed to by fn on each Pet member of each Node
void TraverseTree(const Tree * ptree, void (*fn)(Pet));

// Search for Node matching string name and if found, call
// function pointed to by fn on each Pet member of Node
void ApplyToNode(Pet * ppet, const Tree * ptree, void (*fn)(Pet));

// Delete all Nodes in Tree pointed to by ptree and free all
// allocated memory
void DeleteAll(Tree * ptree);

#endif