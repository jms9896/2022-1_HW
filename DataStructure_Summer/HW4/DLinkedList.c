#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

linkedList* initList() {
	linkedList* L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	return L;
}

int getLength(linkedList* L) {
	return L->length;
}


void insert(linkedList* L, listNode* pre, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	
	// Fill your code
	if (L->head == NULL) {
		newNode->rlink = NULL;
		newNode->llink = NULL;
		L->head = newNode;
	}
	else if (pre == NULL)
		insertFirst(L, x);
	else {
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if (newNode->rlink != NULL)
			newNode->rlink->llink = newNode;
	}
	L->length++;

}

void insertFirst(linkedList* L, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;

	// Fill your code
	if (L->head == NULL) {
		newNode->rlink = NULL;
		newNode->llink = NULL;
		L->head = newNode;
	}
	else {
		newNode->llink = NULL;
		newNode->rlink = L->head;
		newNode->rlink->llink = newNode;
		L->head = newNode;
	}
	L->length++;

}

void insertLast(linkedList* L, element x) {
	listNode *newNode, *temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	// Fill your code
	newNode->rlink = NULL;
	if (L->head == NULL) {
		newNode->llink = NULL;
		L->head = newNode;
	}
	else {
		temp = L->head;
		while (temp->rlink != NULL) 
			temp = temp->rlink;
		newNode->llink = temp;
		temp->rlink = newNode;
	}
	L->length++;
}

int delete(linkedList* L, listNode* p) {
	// Fill your code
	if (L->head == NULL) return FALSE;
	if (p == NULL)	return FALSE;
	if (p->llink == NULL)
		L->head = p->rlink;
	else {
		p->llink->rlink = p->rlink;
	}
	if (p->rlink != NULL)
		p->rlink->llink = p->llink;
	free(p);
	L->length--;
	return TRUE;
}

listNode* search(linkedList* L, element x) {
	listNode* temp = L->head;
	
	while(temp != NULL) {
		if(temp->data == x)
			return temp;
		else
			temp = temp->rlink;
	}
	return temp;
}

void displayList(linkedList* L) {
	listNode* p;
	printf("L=(");
	p = L->head;
	while(p != NULL) {
		printf("%d", p->data);
		p = p->rlink;
		if(p != NULL) printf(", ");
	}
	printf(")\n");
}

void clear(linkedList* L) {
	listNode* p;
	while(L->head != NULL) {
		p = L->head;
		L->head = L->head->rlink;
		free(p);
		p = NULL;
	}
}

