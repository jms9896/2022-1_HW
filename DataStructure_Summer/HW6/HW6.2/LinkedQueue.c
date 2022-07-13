#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

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
	if (isEmpty(Q)) Q->front = newNode;
	else Q->rear->link = newNode;
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
	while(p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// 큐 비우기		
void clear(Queue* Q) {
	queueNode* p;
	while(Q->front) {
		p = Q->front;
		Q->front = Q->front->link;
		free(p);
		p = NULL;
	}
}			

