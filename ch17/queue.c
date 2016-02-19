// queue.c -- implementation of a queue type

#include "queue.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

static void CopyToNode(Item item, Node * pnode)
{
	pnode->item = item;
}

static void CopyToItem(Item * pitem, Node *pnode)
{
	*pitem = pnode->item;
}

void InitializeQueue(Queue * pq) {
	pq->front = NULL;
	pq->rear = NULL;
	pq->items = 0;
}

bool QueueIsFull(const Queue * pq) {
	return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue *pq) {
	return pq->items == 0;
}

int QueueItemCount(const Queue * pq){
	return pq->items;
}

bool EnQueue(Item item, Queue * pq) {
	if (QueueIsFull(pq)) {
		return false;
	}

	Node * new = (Node *) malloc(sizeof(Node));
	if (new == NULL) {
		fprintf(stderr, "Unable to allocate memory!\n");
		exit(EXIT_FAILURE);
	}
	CopyToNode(item, new);
	new->next = NULL;

	if (QueueIsEmpty(pq)) {
		pq->front = new;
	}
	else {
		(pq->rear)->next = new;
	}
	pq->rear = new;
	pq->items++;	// increment items count

	return true;
}

bool DeQueue(Item *pitem, Queue * pq){
	if (QueueIsEmpty(pq)) {
		return false;
	}
	
	Node * first = pq->front;
	CopyToItem(pitem, first);
	pq->front = first->next;
	free(first);

	// decrement items count and set rear pointer to null if necessary
	pq->items--;
	if (pq->items == 0) {
		pq->rear = NULL;
	}
	return true;
}

void EmptyTheQueue(Queue * pq){
	Item tmp;
	while (DeQueue(&tmp, pq))
		continue;
}