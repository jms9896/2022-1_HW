//2015251165 ���μ�
#pragma once
//#ifndef __S_LINKED_LIST2_H__
#define __S_LINKED_LIST2_H__

#define TRUE 1
#define FALSE 0

typedef int element;	// Require modification

// �ܼ����Ḯ��Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode {
	element data;
	struct ListNode* link;
}listNode;

// ����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct LinkedList {
	listNode* head;
	int length;
}linkedList;

linkedList* initList();		// ���鸮��Ʈ ���� 
void insert(linkedList* L, listNode* pre, element x);	// �߰� ���� ���� 
void insertFirst(linkedList* L, element x);				// ù ��° ���� ���� 
void insertLast(linkedList* L, element x);				// ������ ���� ���� 
int delete__(linkedList* L, listNode* p);					// ��� ���� 
listNode* search(linkedList* L, element x);				// �˻� 
int getLength(linkedList* L);							// ����Ʈ�� ����Ǿ� �ִ� �������� �� ��ȯ 
void displayList(linkedList* L);						// ����Ʈ�� ��� ��� ��� 
void clear(linkedList* L);								// ����Ʈ�� ��ü �޸� ���� 
void reverse(linkedList* L);							// ����Ʈ�� ��� ������ �������� �ٲ� 




// �ƾ� �� �ȵ���???

#include <stdio.h>
#include <stdlib.h>
//#include "SLinkedList2.h"

linkedList* initList() {
	linkedList* L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	return L;
}

int getLength(linkedList* L) {		// SLinkedList.c�� ����
	// Fill your code
	return L->length;
}

void insert(linkedList* L, listNode* pre, element x) {	// SLinkedList.c�� ����
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	// Fill your code (�� ��忡 ������ ����)
	newNode->data = x;

	// Fill your code (���� ����Ʈ�� ���)
	if (L->head == NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}

	// Fill your code (ù ��° ���� ���ԵǴ� ���)
	else if (pre == NULL) {
		newNode->link = L->head;
		L->head = newNode;
	}


	// Fill your code (�߰� ���� ���ԵǴ� ���)
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}

	// Fill your code (������ ���� ����)
	L->length++;
}

void insertFirst(linkedList* L, element x) {	// SLinkedList.c�� ����
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	// Fill your code
	newNode->data = x; // ��忡 �����ͻ���
	newNode->link = L->head; // ��ũ ����
	L->head = newNode; // ��� ����
	L->length++;
}

void insertLast(linkedList* L, element x) {	// SLinkedList.c�� ����
	listNode* newNode, * temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	// Fill your code
	newNode->data = x; // ��� ������ ����
	newNode->link = NULL; // ��ũ NULL�� �ʱ�ȭ

	if (L->head == NULL) // ��尡 ���̸� �� ��� ����
		L->head = newNode;
	else {
		temp = L->head; // �ӽÿ� ��尪 �ְ�
		while (temp->link != NULL)
			temp = temp->link; // ����
		temp->link = newNode;
	}
	L->length++;
}

int delete__(linkedList* L, listNode* p) {		// SLinkedList.c�� ����
	listNode* pre;

	// Fill your code (���� ����Ʈ�� ���)
	if (L->head == NULL) return FALSE;
	// Fill your code (������ ��尡 ���� ���)
	if (p == NULL) return FALSE;
	// Fill your code (ù ��° ��尡 ������ ����� ���)
	if (L->head == p) {
		L->head = p->link;
		free(p);
	}

	// Fill your code (�� �̿��� ���)
	else {
		pre = L->head;
		while (pre->link != p) {
			pre = pre->link; // ��ũ ����
			if (pre == NULL) {
				return FALSE;
			}
		}
		pre->link = p->link;
		free(p);
	}

	// Fill your code (������ ���� ����)
	L->length--;

	return TRUE;
}

listNode* search(linkedList* L, element x) {	// SLinkedList.c�� ����
	listNode* P = L->head;

	// Fill your code
	while (P != NULL) { // P�� NULL �ƴϸ�
		if (P->data == x)
			return P;
		else
			P = P->link;
	}
	return P;
}


void displayList(linkedList* L) {
	listNode* p;
	printf("L=(");
	p = L->head;
	while (p != NULL) {
		printf("%s \n", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(")\n");
}

void clear(linkedList* L) {
	listNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

void reverse(linkedList* L) {
	// Fill your code
	listNode* p, * q, * r;
	p = L->head;
	q = NULL;
	r = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link; // switching
		q->link = r; // linking
	}
	L->head = q;

}
