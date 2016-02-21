// tree.h -- interface for a binary search tree data type

#ifndef TREE_H_
#define TREE_H_ 1

#include <stdbool.h>

#define WORD_SIZE 30

// Type definitions

typedef struct 
{
	char word[WORD_SIZE];
	int count;
} Item;

typedef struct node {
	Item item;
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

// Add occurence of string word to Tree pointed to by ptree:
// if a node corresponding to word already exists, increment
// the count member of that node, otherwise create a new Node
// and add it to the Tree, setting its count to 1.
// Return: true if operation succeeds, otherwise false
bool AddWord(const char * word, Tree * ptree);

// Find and remove the Node corresponding the to string word
// in the Tree pointed to by ptree if it exists.
// Return: true if the Node corresponding to word is found
// and deleted, otherwise false
bool DeleteWord(const char * word, Tree * ptree);

// Search for Node corresponding to string word in Tree
// pointed to by ptree.
// Return: true if word is found in Tree, otherwise false
bool InTree(const char * word, const Tree * ptree);

// Visit each Node in Tree pointed to by ptree, calling
// function pointed to by fn on the Item member of each Node
void ApplyToAll(const Tree * ptree, void (*fn)(Item));

// Search for Node matching string word and if found, call
// function pointed to by fn on its item member
void ApplyToNode(const char * word, const Tree * ptree, void (*fn)(Item));

// Delete all Nodes in Tree pointed to by ptree and free all
// allocated memory
void DeleteAll(Tree * ptree);

#endif