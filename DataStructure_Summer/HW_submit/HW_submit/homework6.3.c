//2015251165 정민성
#pragma once
//#ifndef __DEQUE_H__
#define __DEQUE_H__

#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Deque의 노드 구조를 구조체로 정의
typedef struct DequeNode {
	element data;
	struct DequeNode* llink;
	struct DequeNode* rlink;
}dequeNode;

// Queue의 front, rear를 표현할 구조체
typedef struct LinkedDeque {
	dequeNode* front, * rear;
	int length;
}Deque;

Deque* create();						// 공백덱 생성
int isFull(Deque* DQ);					// 덱이 포화상태인지 확인하는 연산
int isEmpty(Deque* DQ);					// 덱이 공백상태인지 확인하는 연산
void insertFront(Deque* DQ, element x);	// 덱의 머리에 요소 추가하는 연산
void insertRear(Deque* DQ, element x);	// 덱의 꼬리에 요소 추가하는 연산
element delete_Front(Deque* DQ);			// 덱의 머리에 위치한 요소 삭제 및 반환하는 연산
element delete_Rear(Deque* DQ);			// 덱의 꼬리에 위치한 요소 삭제 및 반환하는 연산 
element getFront(Deque* DQ);			// 덱의 머리에 위치한 요소 반환하는 연산. 삭제 X
element getRear(Deque* DQ);				// 덱의 꼬리에 위치한 요소 반환하는 연산. 삭제 X
void displayDeque(Deque* DQ);			// 덱의 모든 요소 출력
void clear(Deque* DQ);					// 덱 비우기 

//#endif



#include <stdio.h>
#include <stdlib.h>
//#include "Deque.h"

// 공백덱 생성
Deque* create() {
	Deque* DQ = (Deque*)malloc(sizeof(Deque));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

// 덱이 포화상태인지 확인하는 연산					
int isFull(Deque* DQ) {
	// Fill your code
	return 0;
}

// 덱이 공백상태인지 확인하는 연산				
int isEmpty(Deque* DQ) {
	// Fill your code
	return DQ->front == NULL;
}

// 덱의 머리에 요소 추가하는 연산			
void insertFront(Deque* DQ, element x) {
	// Fill your code
	dequeNode* newNode = (dequeNode*)malloc(sizeof(dequeNode));
	newNode->data = x;

	if (isEmpty(DQ)) {
		newNode->rlink = NULL;
		newNode->llink = NULL;
		DQ->front = newNode;
		DQ->rear = newNode;
	}
	else if (!isEmpty(DQ)) {
		newNode->rlink = DQ->front;
		newNode->llink = NULL;
		DQ->front->llink = newNode;
		DQ->front = newNode;
	}
	else {
		printf("error");
		return;
	}
	DQ->length++;
	return;
}

// 덱의 꼬리에 요소 추가하는 연산
void insertRear(Deque* DQ, element x) {
	// Fill your code
	dequeNode* newNode = (dequeNode*)malloc(sizeof(dequeNode));
	newNode->data = x;

	if (isEmpty(DQ)) {
		newNode->rlink = NULL;
		newNode->llink = NULL;
		DQ->front = newNode;
		DQ->rear = newNode;
	}//여기까지는 같고
	else if (!isEmpty(DQ)) {
		newNode->llink = DQ->front;
		newNode->rlink = NULL;
		//rlink llink만 바꿔주면 될듯
		DQ->front->llink = newNode;
		DQ->front = newNode;
	}
	else {
		printf("error");
		return;
	}
	DQ->length++;
	return;




}

// 덱의 머리에 위치한 요소 삭제 및 반환하는 연산	
element delete_Front(Deque* DQ) {
	// Fill your code
	dequeNode* t;
	element e;

	if (isEmpty(DQ)) {
		printf("Queue emtpy\n");
		return -1;
	}
	else if (!isEmpty(DQ)) {
		t = DQ->front;
		e = t->data;
		DQ->front = t->rlink;
		free(t);
		if (DQ->front == NULL) DQ->rear = NULL;
		return e;
	}
	else {
		printf("error");
		return -1;
	}
	DQ->length--;
}

// 덱의 꼬리에 위치한 요소 삭제 및 반환하는 연산 		
element delete_Rear(Deque* DQ) {
	// Fill your code
	dequeNode* t;
	element e;
	if (isEmpty(DQ)) {
		printf("Queue empty\n");
		return -1;
	}
	else if (!isEmpty(DQ)) {
		t = DQ->rear; //front rear만 바꿔주면 될듯
		e = t->data;
		DQ->rear = DQ->rear->llink;
		DQ->rear->rlink = NULL;
		free(t);

		if (DQ->front == NULL) {
			DQ->rear = NULL;
		}
		return e;
	}
	else {
		printf("error");
		return -1;
	}
	DQ->length--;
}

// 덱의 머리에 위치한 요소 반환하는 연산. 삭제 X		
element getFront(Deque* DQ) {
	// Fill your code
	dequeNode* t;
	element e;
	if (isEmpty(DQ)) {
		printf("Queue empty\n");
		return -1;
	}
	else if (!isEmpty(DQ)) {
		t = DQ->front;
		e = t->data;
		/*DQ->rear = DQ->rear->llink;
		DQ->rear->rlink = NULL;
		free(t);

		if (DQ->front == NULL) {
			DQ->rear = NULL;
		}*/
		return e;
	}
	else {
		printf("error");
		return -1;
	}
	//DQ->length--;

}

// 덱의 꼬리에 위치한 요소 반환하는 연산. 삭제 X		
element getRear(Deque* DQ) {
	// Fill your code
	dequeNode* t;
	element e;
	if (isEmpty(DQ)) {
		printf("Queue empty\n");
		return -1;
	}
	else if (!isEmpty(DQ)) {
		t = DQ->rear;//front rear 바꿔주기
		e = t->data;
		/*DQ->rear = DQ->rear->llink;
		DQ->rear->rlink = NULL;
		free(t);

		if (DQ->front == NULL) {
			DQ->rear = NULL;
		}*/
		return e;
	}
	else {
		printf("error");
		return -1;
	}
	//DQ->length--;




}

// 덱의 모든 요소 출력		
void displayDeque(Deque* DQ) {
	dequeNode* p = DQ->front;
	printf("Deque [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->rlink;
	}
	printf(" ]\n");
}

// 덱 비우기 	
void clear(Deque* DQ) {
	dequeNode* p;
	while (DQ->front) {
		p = DQ->front;
		DQ->front = DQ->front->rlink;
		free(p);
		p = NULL;
	}
}
#include <stdio.h>
//#include "Deque.h"

int main() {
	Deque* DQ;
	element e;
	int i;

	printf("== Deque 생성하기==\n");
	DQ = create();
	displayDeque(DQ);

	printf("\n== front 삽입 10 ==\n");
	insertFront(DQ, 10);	displayDeque(DQ);
	printf("\n== front 삽입 20 ==\n");
	insertFront(DQ, 20);	displayDeque(DQ);
	printf("\n== rear 삽입 30 ==\n");
	insertRear(DQ, 30);	displayDeque(DQ);
	printf("\n== front 삭제==\n");
	e = delete_Front(DQ);	displayDeque(DQ);
	if (e != ERROR)	printf("삭제 데이터: %d\n", e);
	printf("\n== rear 삭제==\n");
	e = delete_Rear(DQ);		displayDeque(DQ);
	if (e != ERROR)	printf("삭제 데이터: %d\n", e);
	printf("\n== rear 삽입 40 ==\n");
	insertRear(DQ, 40);	displayDeque(DQ);
	printf("\n== front 삽입 50 ==\n");
	insertFront(DQ, 50);	displayDeque(DQ);
	printf("\n== front 검색==\n");
	e = getFront(DQ);		displayDeque(DQ);
	if (e != ERROR)	printf("front 데이터: %d\n", e);
	printf("\n== rear 검색==\n");
	e = getRear(DQ);		displayDeque(DQ);
	if (e != ERROR)	printf("rear 데이터: %d\n", e);
	printf("\n== Deque 비우기 ==\n");
	clear(DQ);	displayDeque(DQ);

	return 0;
}

