#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// ����ť ����
Queue* create() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

// ť�� ��ȭ�������� Ȯ���ϴ� ����				
int isFull(Queue* Q) {
	// Fill your code
	return 0;
}

// ť�� ����������� Ȯ���ϴ� ����			
int isEmpty(Queue* Q) {
	// Fill your code
	return Q->front == NULL;
}	

// ť�� rear�� ��Ҹ� �߰��ϴ� ����		
void enqueue(Queue* Q, element x) {
	// Fill your code
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
	newNode->data = x;
	newNode->link = NULL;
	if (isEmpty(Q)) Q->front = newNode;
	else Q->rear->link = newNode;
	Q->rear = newNode;
}

// ť���� ���� ���� ����� ��� ���� �� ��ȯ�ϴ� ����
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

// ť���� ���� ���� ����� ��Ҹ� ��ȯ�ϴ� ����	
element peek(Queue* Q) {
	// Fill your code
	if (isEmpty(Q)) {
		printf("Queue emtpy\n");
		return -1;
	}
	else return Q->front->data;
}	

// ť�� ��� ��� ���	
void displayQueue(Queue* Q) {
	queueNode* p = Q->front;
	printf("Queue [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// ť ����		
void clear(Queue* Q) {
	queueNode* p;
	while(Q->front) {
		p = Q->front;
		Q->front = Q->front->link;
		free(p);
		p = NULL;
	}
}			

