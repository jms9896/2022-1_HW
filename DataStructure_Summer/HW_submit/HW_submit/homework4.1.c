//2015251165 정민성
#pragma once
//#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int element;

// 이중연결리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	element data;
	struct ListNode* llink, * rlink;
}listNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct LinkedList {
	listNode* head;
	int length;
}linkedList;

linkedList* initList();									// 공백리스트 생성 
void insert(linkedList* L, listNode* pre, element x);	// 중간 노드로 삽입 
void insertFirst(linkedList* L, element x);				// 첫 번째 노드로 삽입 
void insertLast(linkedList* L, element x);				// 마지막 노드로 삽입 
int delete_(linkedList* L, listNode* p);					// 노드 삭제 
listNode* search(linkedList* L, element x);				// 검색
int getLength(linkedList* L);							// 리스트에 저장되어 있는 데이터의 수 반환 
void displayList(linkedList* L);						// 리스트의 모든 요소 출력
void clear(linkedList* L);								// 리스트의 전체 메모리 해제 

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
	if (L->head == NULL) { // 헤드값 널이면 l r 초기화
		newNode->rlink = NULL;
		newNode->llink = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) // 널일때 삽입해야하므로
		insertFirst(L, x);
	else { // new r에다 pre r 연결
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
	if (L->head == NULL) { // 헤드가 널이어야하므로,
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
	newNode->rlink = NULL; // last이므로 r이 널
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

	printf("(1)이중 연결 리스트 생성하기\n");
	L = initList();
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));

	printf("\n(2)리스트에 10 노드를 첫 번째 노드로 삽입하기\n");
	insertFirst(L, 10);
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));

	printf("\n(3)리스트의 50 노드를 마지막 노드로 삽입하기\n");
	insertLast(L, 50);
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));

	printf("\n(4)리스트에 5 노드를 첫 번째 노드로 삽입하기\n");
	insertFirst(L, 5);
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));

	printf("\n(5)리스트의 50 노드 뒤에 80 노드를 삽입하기\n");
	p = search(L, 50);
	insert(L, p, 80);
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));

	printf("\n(6)80 노드를 검색하고 삭제하기\n");
	p = search(L, 80);
	if (p == NULL)
		printf("찾는 데이터가 없습니다.\n");
	else
		printf("%d 노드를 찾았습니다\n", p->data);
	if (delete_(L, p))
		printf("노드 삭제 성공!\n");
	else
		printf("노드 삭제 실패!\n");
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));

	printf("\n(7)50 노드 뒤에 70 노드 삽입하기\n");
	p = search(L, 50);
	insert(L, p, 70);
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));

	printf("\n(8)10 노드를 검색하고 삭제하기\n");
	p = search(L, 10);
	if (p == NULL)
		printf("찾는 데이터가 없습니다.\n");
	else
		printf("%d 노드를 찾았습니다\n", p->data);
	if (delete_(L, p))
		printf("노드 삭제 성공!\n");
	else
		printf("노드 삭제 실패!\n");
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));

	return 0;
}

