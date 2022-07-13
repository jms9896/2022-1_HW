// 아쒸 왜 안되지???

#include <stdio.h>
#include <stdlib.h>
#include "SLinkedList2.h"

linkedList* initList() {
	linkedList* L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	return L;
}

int getLength(linkedList* L) {		// SLinkedList.c와 동일
	// Fill your code
	return L->length;
}

void insert(linkedList* L, listNode* pre, element x) {	// SLinkedList.c와 동일
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	// Fill your code (새 노드에 데이터 저장)
	newNode->data = x;

	// Fill your code (공백 리스트인 경우)
	if (L->head == NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}

	// Fill your code (첫 번째 노드로 삽입되는 경우)
	else if (pre == NULL) {
		newNode->link = L->head;
		L->head = newNode;
	}


	// Fill your code (중간 노드로 삽입되는 경우)
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}

	// Fill your code (데이터 개수 증가)
	L->length++;
}

void insertFirst(linkedList* L, element x) {	// SLinkedList.c와 동일
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	// Fill your code
	newNode->data = x; // 노드에 데이터삽입
	newNode->link = L->head; // 링크 연결
	L->head = newNode; // 헤드 연결
	L->length++;
}

void insertLast(linkedList* L, element x) {	// SLinkedList.c와 동일
	listNode *newNode, *temp;
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

int delete(linkedList* L, listNode* p) {		// SLinkedList.c와 동일
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

listNode* search(linkedList* L, element x) {	// SLinkedList.c와 동일
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
	while(p != NULL) {
		printf("%s \n", p->data);
		p = p->link;
		if(p != NULL) printf(", ");
	}
	printf(")\n");
}

void clear(linkedList* L) {
	listNode* p;
	while(L->head != NULL) {
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
