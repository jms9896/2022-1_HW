//2015251165 정민성
#pragma once
//#ifndef __LINKED_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Queue의 노드 구조를 구조체로 정의
typedef struct QueueNode {
	element data;
	struct QueueNode* link;
}queueNode;

// Queue의 front, rear를 표현할 구조체
typedef struct LinkedQueue {
	queueNode* front, * rear;
}Queue;

Queue* create();					// 공백큐 생성
int isFull(Queue* Q);				// 큐가 포화상태인지 확인하는 연산
int isEmpty(Queue* Q);				// 큐가 공백상태인지 확인하는 연산
void enqueue(Queue* Q, element x);	// 큐의 rear에 요소를 추가하는 연산
element dequeue(Queue* Q);			// 큐에서 가장 먼저 저장된 요소 삭제 및 반환하는 연산
element peek(Queue* Q);				// 큐에서 가장 먼저 저장된 요소를 반환하는 연산
void displayQueue(Queue* Q);		// 큐의 모든 요소 출력
void clear(Queue* Q);				// 큐 비우기 

//#endif



#include <stdio.h>
#include <stdlib.h>
//#include "LinkedQueue.h"

// 공백큐 생성
Queue* create() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

// 큐가 포화상태인지 확인하는 연산				
int isFull(Queue* Q) {
	// Fill your code
	return 0;
}

// 큐가 공백상태인지 확인하는 연산			
int isEmpty(Queue* Q) {
	// Fill your code
	return Q->front == NULL;
}

// 큐의 rear에 요소를 추가하는 연산		
void enqueue(Queue* Q, element x) {
	// Fill your code
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
	newNode->data = x;
	newNode->link = NULL;
	if (isEmpty(Q)) {
		Q->front = newNode;
	}// 
	else {
		Q->rear->link = newNode;
	}
	Q->rear = newNode;
}

// 큐에서 가장 먼저 저장된 요소 삭제 및 반환하는 연산
element dequeue(Queue* Q) {
	// Fill your code
	queueNode* t;
	element e;

	if (isEmpty(Q)) {
		printf("Queue empty\n");
		return -1;
	}
	else {
		t = Q->front;
		e = t->data;
		Q->front = t->link;
		free(t);
		if (Q->front == NULL) Q->rear = NULL;
		return e;
	}

}

// 큐에서 가장 먼저 저장된 요소를 반환하는 연산	
element peek(Queue* Q) {
	// Fill your code
	if (isEmpty(Q)) {
		printf("Queue emtpy\n");
		return -1;
	}
	else return Q->front->data;
}

// 큐의 모든 요소 출력	
void displayQueue(Queue* Q) {
	queueNode* p = Q->front;
	printf("Queue [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// 큐 비우기		
void clear(Queue* Q) {
	queueNode* p;
	while (Q->front) {
		p = Q->front;
		Q->front = Q->front->link;
		free(p);
		p = NULL;
	}
}

#include <stdio.h>
//#include "LinkedQueue.h"

int main() {
	Queue* Q;
	element item;
	int i;

	printf("(1) 공백 큐 생성하기\n");
	Q = create();
	displayQueue(Q);

	printf("\n(2) 큐에 10, 20, 30을 차례로 삽입\n");
	enqueue(Q, 10);
	displayQueue(Q);
	enqueue(Q, 20);
	displayQueue(Q);
	enqueue(Q, 30);
	displayQueue(Q);

	printf("\n(3) 가장 먼저 삽입된 요소를 출력\n");
	item = peek(Q);
	if (item != ERROR)
		printf("가장 먼저 삽입된 요소: %d\n", item);
	displayQueue(Q);

	printf("\n(4) 데이터 삭제 4번 수행\n");
	for (i = 0; i < 4; i++) {
		item = dequeue(Q);
		if (item != ERROR) {
			printf("%d 삭제\n", item);
			displayQueue(Q);
		}
		else {
			displayQueue(Q);
			break;
		}
	}

	printf("\n(5) 큐 비우기\n");
	clear(Q);
	displayQueue(Q);

	return 0;
}

