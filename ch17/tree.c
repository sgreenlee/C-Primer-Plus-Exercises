// tree.c -- implementation for binary search tree data type

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

Tree * InitializeTree(Tree * ptree) {
	*ptree = NULL;
	return ptree;
}

bool TreeIsEmpty(const Tree * ptree) {
	return (*ptree == NULL);
}

bool TreeIsFull(const Tree * ptree) {
	Node * pnode = (Node *) malloc(sizeof(Node));
	if (pnode == NULL) {
		return true;
	}
	else {
		free(pnode);
		return false;
	}
}

bool AddWord(const char * word, Tree * ptree) {
	if (TreeIsFull(ptree)) {
		return false;
	}

	int cmp;
	while (*ptree != NULL) {
		int cmp = strcmp(word, (*ptree)->item.word);
		if (cmp == 0) {
			(*ptree)->item.count++;
			return true;
		}
		else if (cmp < 0) {
			ptree = &((*ptree)->left);
		}
		else {
			ptree = &((*ptree)->right);
		}
	}

	Item item;
	strncpy(item.word, word, WORD_SIZE);
	item.count = 1;

	Node * pnode = (Node *) malloc(sizeof(Node));
	if (pnode == NULL) {
		fprintf(stderr, "Could not allocate memory.\n");
		return false;
	}

	pnode->item = item;
	pnode->left = NULL;
	pnode->right = NULL;

	*ptree = pnode;
	return true;
}

bool DeleteWord(const char * word, Tree * ptree) {
	while (*ptree != NULL) {
		int cmp = strcmp(word, (*ptree)->item.word);
		if (cmp == 0) {
			// delete this node
			Node * right = (*ptree)->right;
			Node * tmp = (*ptree);
			*ptree = (*ptree)->left;
			while ((*ptree)->right != NULL) {
				ptree = &((*ptree)->right);
			}
			(*ptree)->right = right;

			free(tmp);
			return true;
		}
		else if (cmp < 0) {
			ptree = &((*ptree)->left);
		}
		else {
			ptree = &((*ptree)->right);
		}
	}
	return false;

}

bool InTree(const char * word, const Tree * ptree) {
	Node * pnode = *ptree;
	while (pnode != NULL) {
		int cmp = strcmp(word, pnode->item.word);
		if (cmp == 0) {
			return true;
		}
		else if (cmp < 0) {
			pnode = pnode->left;
		}
		else {
			pnode = pnode->right;
		}
	}
	return false;
}

void ApplyToNode(const char * word, const Tree * ptree, void (*fn)(Item)) {
	Node * pnode = *ptree;
	while (pnode != NULL) {
		int cmp = strcmp(word, pnode->item.word);
		if (cmp == 0) {
			(*fn)(pnode->item);
			return;
		}
		else if (cmp < 0) {
			pnode = pnode->left;
		}
		else {
			pnode = pnode->right;
		}
	}
	return;
}

void ApplyToAll(const Tree * ptree, void (*fn)(Item)) {
	Node * pnode = *ptree;
	if (pnode == NULL) {
		return;
	}
	ApplyToAll(&(pnode->left), fn);
	(*fn)(pnode->item);
	ApplyToAll(&(pnode->right), fn);
}

void DeleteAll(Tree * ptree) {
	Node * pnode = *ptree;
	DeleteAll(&(pnode->left));
	DeleteAll(&(pnode->right));
	free(pnode);
}