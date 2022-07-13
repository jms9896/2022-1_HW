//2015251165 ���μ�
#pragma once
//#ifndef __LINKED_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Queue�� ��� ������ ����ü�� ����
typedef struct QueueNode {
	element data;
	struct QueueNode* link;
}queueNode;

// Queue�� front, rear�� ǥ���� ����ü
typedef struct LinkedQueue {
	queueNode* front, * rear;
}Queue;

Queue* create();					// ����ť ����
int isFull(Queue* Q);				// ť�� ��ȭ�������� Ȯ���ϴ� ����
int isEmpty(Queue* Q);				// ť�� ����������� Ȯ���ϴ� ����
void enqueue(Queue* Q, element x);	// ť�� rear�� ��Ҹ� �߰��ϴ� ����
element dequeue(Queue* Q);			// ť���� ���� ���� ����� ��� ���� �� ��ȯ�ϴ� ����
element peek(Queue* Q);				// ť���� ���� ���� ����� ��Ҹ� ��ȯ�ϴ� ����
void displayQueue(Queue* Q);		// ť�� ��� ��� ���
void clear(Queue* Q);				// ť ���� 

//#endif



#include <stdio.h>
#include <stdlib.h>
//#include "LinkedQueue.h"

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
	if (isEmpty(Q)) {
		Q->front = newNode;
	}// 
	else {
		Q->rear->link = newNode;
	}
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
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// ť ����		
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

	printf("(1) ���� ť �����ϱ�\n");
	Q = create();
	displayQueue(Q);

	printf("\n(2) ť�� 10, 20, 30�� ���ʷ� ����\n");
	enqueue(Q, 10);
	displayQueue(Q);
	enqueue(Q, 20);
	displayQueue(Q);
	enqueue(Q, 30);
	displayQueue(Q);

	printf("\n(3) ���� ���� ���Ե� ��Ҹ� ���\n");
	item = peek(Q);
	if (item != ERROR)
		printf("���� ���� ���Ե� ���: %d\n", item);
	displayQueue(Q);

	printf("\n(4) ������ ���� 4�� ����\n");
	for (i = 0; i < 4; i++) {
		item = dequeue(Q);
		if (item != ERROR) {
			printf("%d ����\n", item);
			displayQueue(Q);
		}
		else {
			displayQueue(Q);
			break;
		}
	}

	printf("\n(5) ť ����\n");
	clear(Q);
	displayQueue(Q);

	return 0;
}

