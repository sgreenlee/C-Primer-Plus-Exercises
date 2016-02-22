// pettree.c -- implementation for binary search tree linked list data type

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "pettree.h"

static bool AddItemToList(Pet * ppet, List * plist);
static int ListCount(List * plist);
static bool InList(Pet * ppet, List * plist);
static void TraverseList(List * plist, void (*fn)(Pet));
static void DeleteList(List * plist);
static bool DeleteListItem(Pet * ppet, List * plist);

Tree * InitializeTree(Tree * ptree) {
	*ptree = NULL;
	return ptree;
}

bool TreeIsEmpty(const Tree * ptree) {
	return (*ptree == NULL);
}

bool TreeIsFull(const Tree * ptree) {
	Node * pnode = (Node *) malloc(sizeof(Node));
	Pet * ppet = (Pet *) malloc(sizeof(Pet));
	if (pnode == NULL || ppet == NULL) {
		return true;
	}
	else {
		free(pnode);
		free(ppet);
		return false;
	}
}

bool AddPet(Pet * ppet, Tree * ptree) {
	if (TreeIsFull(ptree)) {
		return false;
	}

	int cmp;
	while (*ptree != NULL) {
		int cmp = strcmp(ppet->name, (*ptree)->name);
		if (cmp == 0) {
			// add new pet item to list in Node
			return AddItemToList(ppet, &((*ptree)->head));
		}
		else if (cmp < 0) {
			ptree = &((*ptree)->left);
		}
		else {
			ptree = &((*ptree)->right);
		}
	}

	// create a new node if one doesn't already exist
	Node * pnode = (Node *) malloc(sizeof(Node));
	if (pnode == NULL) {
		fprintf(stderr, "Could not allocate memory.\n");
		return false;
	}

	strncpy(pnode->name, ppet->name, STRLEN);
	pnode->head = ppet;
	pnode->left = NULL;
	pnode->right = NULL;

	*ptree = pnode;
	return true;
}

bool DeletePet(Pet * ppet, Tree * ptree) {
	while (*ptree != NULL) {
		int cmp = strcmp(ppet->name, (*ptree)->name);
		if (cmp == 0) {
			List * plist = &((*ptree)->head);
			bool deleted = DeleteListItem(ppet, plist);
			// the list at this node is empty, delete the entire node
			if ((*ptree)->head == NULL) {
				Node * tmp = (*ptree);
				if ((*ptree)->left == NULL) {
					*ptree = (*ptree)->right;
				}
				else {
					Node * right = (*ptree)->right;
					*ptree = (*ptree)->left;
					// reattach right subtree
					if (right != NULL) {
						while ((*ptree)->right != NULL) {
							*ptree = (*ptree)->right;
						}
						(*ptree)->right = right;
					}
				}
				free(tmp);
			}
			return deleted;
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

bool InTree(Pet * ppet, const Tree * ptree) {
	Node * pnode = *ptree;
	while (pnode != NULL) {
		int cmp = strcmp(ppet->name, pnode->name);
		if (cmp == 0) {
			return InList(ppet, &(pnode->head));
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

int TreeItemCount(Tree tree) {
	int count = 0;
	if (tree == NULL) {
		return count;
	}
	count += ListCount(&(tree->head));
	count += TreeItemCount(tree->left);
	count += TreeItemCount(tree->right);
	return count;
}

void ApplyToNode(Pet * ppet, const Tree * ptree, void (*fn)(Pet)) {
	Node * pnode = *ptree;
	while (pnode != NULL) {
		int cmp = strcmp(ppet->name, pnode->name);
		if (cmp == 0) {
			TraverseList(&(pnode->head), fn);
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

void TraverseTree(const Tree * ptree, void (*fn)(Pet)) {
	Node * pnode = *ptree;
	if (pnode == NULL) {
		return;
	}
	TraverseTree(&(pnode->left), fn);
	TraverseList(&(pnode->head), fn);
	TraverseTree(&(pnode->right), fn);
}

void DeleteAll(Tree * ptree) {
	if (*ptree == NULL) {
		return;
	}
	Node * pnode = *ptree;
	DeleteAll(&(pnode->left));
	DeleteAll(&(pnode->right));
	DeleteList(&(pnode->head));
	free(pnode);
}

static bool AddItemToList(Pet * ppet, List * plist) {
	if (*plist == NULL) {
		*plist = ppet;
	}
	else {
		Pet * current = *plist;
		while(current->next != NULL) {
			current = current->next;
		}
		current->next = ppet;
	}
	ppet->next = NULL;
	return true;
}

static int ListCount(List * plist) {
	int count = 0;
	Pet * ppet = *plist;
	while (ppet != NULL) {
		count++;
		ppet = ppet->next;
	}
	return count;
}

static bool InList(Pet * ppet, List * plist) {
	while (*plist != NULL) {
		if (strcmp(ppet->name, (*plist)->name) == 0)
			if (strcmp(ppet->type, (*plist)->type) == 0)
				return true;
	}
	return false;
}

static void TraverseList(List * plist, void (*fn)(Pet)) {
	Pet * ppet = *plist;
	while (ppet != NULL) {
		fn(*ppet);
		ppet = ppet->next;
	}
}

static void DeleteList(List * plist) {
	Pet * save, * ppet = *plist;
	while (ppet != NULL) {
		save = ppet;
		ppet = ppet->next;
		free(save);
	}
	*plist = NULL;
}

static bool DeleteListItem(Pet * ppet, List * plist) {
	Pet * save;
	while (*plist != NULL) {
		if (strcmp((*plist)->type, ppet->type) == 0 &&
			strcmp((*plist)->name, ppet->name) == 0 ) {
				save = *plist;
				*plist = (*plist)->next;
				free(save);
				return true;
		}
		plist = &((*plist)->next);
	}
	return false;
}