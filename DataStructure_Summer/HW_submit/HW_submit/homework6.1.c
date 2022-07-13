//2015251165 정민성
#pragma once
//#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define MAX_SIZE 100
#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Queue를 구조체로 정의
typedef struct CircularQueue {
	element queue[MAX_SIZE];
	int front, rear;
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
//#include "CircularQueue.h"

// 공백큐 생성
Queue* create() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = 0;
	Q->rear = 0;
	return Q;
}

// 큐가 포화상태인지 확인하는 연산				
int isFull(Queue* Q) {
	// Fill your code
	return ((Q->rear + 1) % MAX_SIZE == Q->front);

}

// 큐가 공백상태인지 확인하는 연산			
int isEmpty(Queue* Q) {
	// Fill your code
	return Q->front == Q->rear;

}

// 큐의 rear에 요소를 추가하는 연산		
void enqueue(Queue* Q, element x) {
	// Fill your code
	if (isFull(Q)) {
		printf("Queue is  full\n");
		return;
	}
	else {
		Q->rear = (Q->rear + 1) % MAX_SIZE; // %이용해서 값 삽입
		Q->queue[Q->rear] = x;
	}

}

// 큐에서 가장 먼저 저장된 요소 삭제 및 반환하는 연산
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

// 큐에서 가장 먼저 저장된 요소를 반환하는 연산	
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

// 큐의 모든 요소 출력	
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

// 큐 비우기		
void clear(Queue* Q) {
	Q->rear = Q->front;
}
#include <stdio.h>
//#include "CircularQueue.h"

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
