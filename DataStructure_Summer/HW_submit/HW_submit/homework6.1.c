//2015251165 ���μ�
#pragma once
//#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define MAX_SIZE 100
#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Queue�� ����ü�� ����
typedef struct CircularQueue {
	element queue[MAX_SIZE];
	int front, rear;
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
//#include "CircularQueue.h"

// ����ť ����
Queue* create() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = 0;
	Q->rear = 0;
	return Q;
}

// ť�� ��ȭ�������� Ȯ���ϴ� ����				
int isFull(Queue* Q) {
	// Fill your code
	return ((Q->rear + 1) % MAX_SIZE == Q->front);

}

// ť�� ����������� Ȯ���ϴ� ����			
int isEmpty(Queue* Q) {
	// Fill your code
	return Q->front == Q->rear;

}

// ť�� rear�� ��Ҹ� �߰��ϴ� ����		
void enqueue(Queue* Q, element x) {
	// Fill your code
	if (isFull(Q)) {
		printf("Queue is  full\n");
		return;
	}
	else {
		Q->rear = (Q->rear + 1) % MAX_SIZE; // %�̿��ؼ� �� ����
		Q->queue[Q->rear] = x;
	}

}

// ť���� ���� ���� ����� ��� ���� �� ��ȯ�ϴ� ����
element dequeue(Queue* Q) {
	// Fill your code
	if (isEmpty(Q)) {
		printf("Queue is empty\n");
		return -1;
	}
	else {
		Q->front = (Q->front + 1) % MAX_SIZE;
		return Q->queue[Q->front];
	}

}

// ť���� ���� ���� ����� ��Ҹ� ��ȯ�ϴ� ����	
element peek(Queue* Q) {
	// Fill your code
	if (isEmpty(Q)) {
		printf("Queue is empty\n");
		return -1;
	}
	else {
		return Q->queue[(Q->front + 1) % MAX_SIZE];
	}

}

// ť�� ��� ��� ���	
void displayQueue(Queue* Q) {
	int i, first, rear;
	first = (Q->front + 1) % MAX_SIZE;
	rear = (Q->rear + 1) % MAX_SIZE;
	i = first;
	printf("QUEUE [ ");
	while (i != rear) {
		printf("%d ", Q->queue[i]);
		i = (i + 1) % MAX_SIZE;
	}
	printf(" ]\tfront: %d\trear: %d\n", Q->front, Q->rear);
}

// ť ����		
void clear(Queue* Q) {
	Q->rear = Q->front;
}
#include <stdio.h>
//#include "CircularQueue.h"

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
