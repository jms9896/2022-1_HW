//2015251165 ���μ�
#pragma once
//#ifndef __S_LINKED_LIST_H__
#define __S_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int element;

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

//#endif


#include <stdio.h>
#include <stdlib.h>
//#include "SLinkedList.h"

linkedList* initList() {
	linkedList* L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	return L;
}

int getLength(linkedList* L) {
	// Fill your code
	return L->length; // ���̸� �������� �ǹǷ�
}

void insert(linkedList* L, listNode* pre, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	// Fill your code (�� ��忡 ������ ����)
	newNode->data = x; // ������ x ����

	// Fill your code (���� ����Ʈ�� ���)
	if (L->head == NULL) { // �����ΰ�?
		newNode->link = NULL; // ��ũ�� �ʱ�ȭ
		L->head = newNode; // ��尪 ����
	}

	// Fill your code (ù ��° ���� ���ԵǴ� ���)
	else if (pre == NULL) { // �����ΰ�?
		newNode->link = L->head; // "
		L->head = newNode; // "
	}


	// Fill your code (�߰� ���� ���ԵǴ� ���)
	else {// ���� �ƴѰ��
		newNode->link = pre->link; 
		pre->link = newNode; // ����
	}

	// Fill your code (������ ���� ����)
	L->length++;
}

void insertFirst(linkedList* L, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	// Fill your code
	newNode->data = x; // ��忡 �����ͻ���
	newNode->link = L->head; // ��ũ ����
	L->head = newNode; // ��� ����
	L->length++;
}

void insertLast(linkedList* L, element x) {
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

int delete__(linkedList* L, listNode* p) {
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

listNode* search(linkedList* L, element x) {
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
		printf("%d", p->data);
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


#include <stdio.h>
//#include "SLinkedList.h"

int main() {
	linkedList* L;
	listNode* p;

	printf("(1)���鸮��Ʈ �����ϱ�\n");
	// Fill your code
	L = initList(); // L �ʱ�ȭ
	displayList(L); // L ���

	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));

	printf("\n(2)����Ʈ�� 10, 50, 80 ��带 ������� �����ϱ�\n");
	// Fill your code
	insertLast(L, 10);
	insertLast(L, 80);
	insertLast(L, 50);
	displayList(L);

	printf("����Ʈ�� ����� ������ ����: %d\n", L->length);
	printf("\n(3)����Ʈ���� 50 ��� Ž���ϱ�\n");
	// Fill your code
	p = search(L, 50);
	if (p == NULL)
		printf("No Data\n");
	else
		printf("%d Find Data\n", p->data);

	printf("\n(4)50 ��� �ڿ� 60 ��� �����ϱ�\n");
	// Fill your code
	insert(L, p, 40);
	displayList(L);

	printf("����Ʈ�� ����� ������ ����: %d\n", L->length);
	printf("\n(5)����Ʈ���� 80 ��� �����ϱ�\n");
	// Fill your code
	p = search(L, 80);
	if (delete__(L, p))
		printf("Del success!\n");
	else
		printf("Del fail!\n");
	displayList(L);
	printf("Num of Data in list: %d\n", getLength(L));




	clear(L);

	return 0;
}
