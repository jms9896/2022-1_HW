//2015251165 정민성
#pragma once
//#ifndef __S_LINKED_LIST_H__
#define __S_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int element;

// 단순연결리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	element data;
	struct ListNode* link;
}listNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct LinkedList {
	listNode* head;
	int length;
}linkedList;

linkedList* initList();		// 공백리스트 생성 
void insert(linkedList* L, listNode* pre, element x);	// 중간 노드로 삽입 
void insertFirst(linkedList* L, element x);				// 첫 번째 노드로 삽입 
void insertLast(linkedList* L, element x);				// 마지막 노드로 삽입 
int delete__(linkedList* L, listNode* p);					// 노드 삭제 
listNode* search(linkedList* L, element x);				// 검색 
int getLength(linkedList* L);							// 리스트에 저장되어 있는 데이터의 수 반환 
void displayList(linkedList* L);						// 리스트의 모든 요소 출력
void clear(linkedList* L);								// 리스트의 전체 메모리 해제 

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
	return L->length; // 길이만 가져오면 되므로
}

void insert(linkedList* L, listNode* pre, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	// Fill your code (새 노드에 데이터 저장)
	newNode->data = x; // 데이터 x 저장

	// Fill your code (공백 리스트인 경우)
	if (L->head == NULL) { // 공백인가?
		newNode->link = NULL; // 링크값 초기화
		L->head = newNode; // 헤드값 연결
	}

	// Fill your code (첫 번째 노드로 삽입되는 경우)
	else if (pre == NULL) { // 공백인가?
		newNode->link = L->head; // "
		L->head = newNode; // "
	}


	// Fill your code (중간 노드로 삽입되는 경우)
	else {// 공백 아닌경우
		newNode->link = pre->link; 
		pre->link = newNode; // 연결
	}

	// Fill your code (데이터 개수 증가)
	L->length++;
}

void insertFirst(linkedList* L, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	// Fill your code
	newNode->data = x; // 노드에 데이터삽입
	newNode->link = L->head; // 링크 연결
	L->head = newNode; // 헤드 연결
	L->length++;
}

void insertLast(linkedList* L, element x) {
	listNode* newNode, * temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	// Fill your code
	newNode->data = x; // 노드 데이터 삽입
	newNode->link = NULL; // 링크 NULL로 초기화

	if (L->head == NULL) // 헤드가 널이면 새 노드 삽입
		L->head = newNode;
	else {
		temp = L->head; // 임시에 헤드값 넣고
		while (temp->link != NULL)
			temp = temp->link; // 연결
		temp->link = newNode;
	}
	L->length++;
}

int delete__(linkedList* L, listNode* p) {
	listNode* pre;

	// Fill your code (공백 리스트인 경우)
	if (L->head == NULL) return FALSE;
	// Fill your code (삭제할 노드가 없는 경우)
	if (p == NULL) return FALSE;
	// Fill your code (첫 번째 노드가 삭제할 노드인 경우)
	if (L->head == p) {
		L->head = p->link;
		free(p);
	}

	// Fill your code (그 이외의 경우)
	else {
		pre = L->head;
		while (pre->link != p) {
			pre = pre->link; // 링크 연결
			if (pre == NULL) {
				return FALSE;
			}
		}
		pre->link = p->link;
		free(p);
	}

	// Fill your code (데이터 개수 감소)
	L->length--;

	return TRUE;
}

listNode* search(linkedList* L, element x) {
	listNode* P = L->head;

	// Fill your code
	while (P != NULL) { // P값 NULL 아니면
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

	printf("(1)공백리스트 생성하기\n");
	// Fill your code
	L = initList(); // L 초기화
	displayList(L); // L 출력

	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));

	printf("\n(2)리스트에 10, 50, 80 노드를 순서대로 삽입하기\n");
	// Fill your code
	insertLast(L, 10);
	insertLast(L, 80);
	insertLast(L, 50);
	displayList(L);

	printf("리스트에 저장된 데이터 개수: %d\n", L->length);
	printf("\n(3)리스트에서 50 노드 탐색하기\n");
	// Fill your code
	p = search(L, 50);
	if (p == NULL)
		printf("No Data\n");
	else
		printf("%d Find Data\n", p->data);

	printf("\n(4)50 노드 뒤에 60 노드 삽입하기\n");
	// Fill your code
	insert(L, p, 40);
	displayList(L);

	printf("리스트에 저장된 데이터 개수: %d\n", L->length);
	printf("\n(5)리스트에서 80 노드 삭제하기\n");
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
