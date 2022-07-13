//2015251165 ���μ�
#pragma once
//#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int element;

// ���߿��Ḯ��Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode {
	element data;
	struct ListNode* llink, * rlink;
}listNode;

// ����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct LinkedList {
	listNode* head;
	int length;
}linkedList;

linkedList* initList();									// ���鸮��Ʈ ���� 
void insert(linkedList* L, listNode* pre, element x);	// �߰� ���� ���� 
void insertFirst(linkedList* L, element x);				// ù ��° ���� ���� 
void insertLast(linkedList* L, element x);				// ������ ���� ���� 
int delete_(linkedList* L, listNode* p);					// ��� ���� 
listNode* search(linkedList* L, element x);				// �˻�
int getLength(linkedList* L);							// ����Ʈ�� ����Ǿ� �ִ� �������� �� ��ȯ 
void displayList(linkedList* L);						// ����Ʈ�� ��� ��� ���
void clear(linkedList* L);								// ����Ʈ�� ��ü �޸� ���� 

//#endif


#include <stdio.h>
#include <stdlib.h>
//#include "DLinkedList.h"

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
	if (L->head == NULL) { // ��尪 ���̸� l r �ʱ�ȭ
		newNode->rlink = NULL;
		newNode->llink = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) // ���϶� �����ؾ��ϹǷ�
		insertFirst(L, x);
	else { // new r���� pre r ����
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
	if (L->head == NULL) { // ��尡 ���̾���ϹǷ�,
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
	listNode* newNode, * t;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	// Fill your code
	newNode->rlink = NULL; // last�̹Ƿ� r�� ��
	if (L->head == NULL) {
		newNode->llink = NULL;
		L->head = newNode;
	}
	else {
		t = L->head;
		while (t->rlink != NULL)
			t = t->rlink;
		newNode->llink = t;
		t->rlink = newNode;
	}
	L->length++;
}

int delete_(linkedList* L, listNode* p) {
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

	while (temp != NULL) {
		if (temp->data == x)
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
	while (p != NULL) {
		printf("%d", p->data);
		p = p->rlink;
		if (p != NULL) printf(", ");
	}
	printf(")\n");
}

void clear(linkedList* L) {
	listNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->rlink;
		free(p);
		p = NULL;
	}
}

#include <stdio.h>
//#include "DLinkedList.h"

int main() {
	linkedList* L;
	listNode* p;

	printf("(1)���� ���� ����Ʈ �����ϱ�\n");
	L = initList();
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));

	printf("\n(2)����Ʈ�� 10 ��带 ù ��° ���� �����ϱ�\n");
	insertFirst(L, 10);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));

	printf("\n(3)����Ʈ�� 50 ��带 ������ ���� �����ϱ�\n");
	insertLast(L, 50);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));

	printf("\n(4)����Ʈ�� 5 ��带 ù ��° ���� �����ϱ�\n");
	insertFirst(L, 5);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));

	printf("\n(5)����Ʈ�� 50 ��� �ڿ� 80 ��带 �����ϱ�\n");
	p = search(L, 50);
	insert(L, p, 80);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));

	printf("\n(6)80 ��带 �˻��ϰ� �����ϱ�\n");
	p = search(L, 80);
	if (p == NULL)
		printf("ã�� �����Ͱ� �����ϴ�.\n");
	else
		printf("%d ��带 ã�ҽ��ϴ�\n", p->data);
	if (delete_(L, p))
		printf("��� ���� ����!\n");
	else
		printf("��� ���� ����!\n");
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));

	printf("\n(7)50 ��� �ڿ� 70 ��� �����ϱ�\n");
	p = search(L, 50);
	insert(L, p, 70);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));

	printf("\n(8)10 ��带 �˻��ϰ� �����ϱ�\n");
	p = search(L, 10);
	if (p == NULL)
		printf("ã�� �����Ͱ� �����ϴ�.\n");
	else
		printf("%d ��带 ã�ҽ��ϴ�\n", p->data);
	if (delete_(L, p))
		printf("��� ���� ����!\n");
	else
		printf("��� ���� ����!\n");
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));

	return 0;
}

