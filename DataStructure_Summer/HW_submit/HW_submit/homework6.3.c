//2015251165 ���μ�
#pragma once
//#ifndef __DEQUE_H__
#define __DEQUE_H__

#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Deque�� ��� ������ ����ü�� ����
typedef struct DequeNode {
	element data;
	struct DequeNode* llink;
	struct DequeNode* rlink;
}dequeNode;

// Queue�� front, rear�� ǥ���� ����ü
typedef struct LinkedDeque {
	dequeNode* front, * rear;
	int length;
}Deque;

Deque* create();						// ���鵦 ����
int isFull(Deque* DQ);					// ���� ��ȭ�������� Ȯ���ϴ� ����
int isEmpty(Deque* DQ);					// ���� ����������� Ȯ���ϴ� ����
void insertFront(Deque* DQ, element x);	// ���� �Ӹ��� ��� �߰��ϴ� ����
void insertRear(Deque* DQ, element x);	// ���� ������ ��� �߰��ϴ� ����
element delete_Front(Deque* DQ);			// ���� �Ӹ��� ��ġ�� ��� ���� �� ��ȯ�ϴ� ����
element delete_Rear(Deque* DQ);			// ���� ������ ��ġ�� ��� ���� �� ��ȯ�ϴ� ���� 
element getFront(Deque* DQ);			// ���� �Ӹ��� ��ġ�� ��� ��ȯ�ϴ� ����. ���� X
element getRear(Deque* DQ);				// ���� ������ ��ġ�� ��� ��ȯ�ϴ� ����. ���� X
void displayDeque(Deque* DQ);			// ���� ��� ��� ���
void clear(Deque* DQ);					// �� ���� 

//#endif



#include <stdio.h>
#include <stdlib.h>
//#include "Deque.h"

// ���鵦 ����
Deque* create() {
	Deque* DQ = (Deque*)malloc(sizeof(Deque));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

// ���� ��ȭ�������� Ȯ���ϴ� ����					
int isFull(Deque* DQ) {
	// Fill your code
	return 0;
}

// ���� ����������� Ȯ���ϴ� ����				
int isEmpty(Deque* DQ) {
	// Fill your code
	return DQ->front == NULL;
}

// ���� �Ӹ��� ��� �߰��ϴ� ����			
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

// ���� ������ ��� �߰��ϴ� ����
void insertRear(Deque* DQ, element x) {
	// Fill your code
	dequeNode* newNode = (dequeNode*)malloc(sizeof(dequeNode));
	newNode->data = x;

	if (isEmpty(DQ)) {
		newNode->rlink = NULL;
		newNode->llink = NULL;
		DQ->front = newNode;
		DQ->rear = newNode;
	}//��������� ����
	else if (!isEmpty(DQ)) {
		newNode->llink = DQ->front;
		newNode->rlink = NULL;
		//rlink llink�� �ٲ��ָ� �ɵ�
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

// ���� �Ӹ��� ��ġ�� ��� ���� �� ��ȯ�ϴ� ����	
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

// ���� ������ ��ġ�� ��� ���� �� ��ȯ�ϴ� ���� 		
element delete_Rear(Deque* DQ) {
	// Fill your code
	dequeNode* t;
	element e;
	if (isEmpty(DQ)) {
		printf("Queue empty\n");
		return -1;
	}
	else if (!isEmpty(DQ)) {
		t = DQ->rear; //front rear�� �ٲ��ָ� �ɵ�
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

// ���� �Ӹ��� ��ġ�� ��� ��ȯ�ϴ� ����. ���� X		
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

// ���� ������ ��ġ�� ��� ��ȯ�ϴ� ����. ���� X		
element getRear(Deque* DQ) {
	// Fill your code
	dequeNode* t;
	element e;
	if (isEmpty(DQ)) {
		printf("Queue empty\n");
		return -1;
	}
	else if (!isEmpty(DQ)) {
		t = DQ->rear;//front rear �ٲ��ֱ�
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

// ���� ��� ��� ���		
void displayDeque(Deque* DQ) {
	dequeNode* p = DQ->front;
	printf("Deque [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->rlink;
	}
	printf(" ]\n");
}

// �� ���� 	
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

	printf("== Deque �����ϱ�==\n");
	DQ = create();
	displayDeque(DQ);

	printf("\n== front ���� 10 ==\n");
	insertFront(DQ, 10);	displayDeque(DQ);
	printf("\n== front ���� 20 ==\n");
	insertFront(DQ, 20);	displayDeque(DQ);
	printf("\n== rear ���� 30 ==\n");
	insertRear(DQ, 30);	displayDeque(DQ);
	printf("\n== front ����==\n");
	e = delete_Front(DQ);	displayDeque(DQ);
	if (e != ERROR)	printf("���� ������: %d\n", e);
	printf("\n== rear ����==\n");
	e = delete_Rear(DQ);		displayDeque(DQ);
	if (e != ERROR)	printf("���� ������: %d\n", e);
	printf("\n== rear ���� 40 ==\n");
	insertRear(DQ, 40);	displayDeque(DQ);
	printf("\n== front ���� 50 ==\n");
	insertFront(DQ, 50);	displayDeque(DQ);
	printf("\n== front �˻�==\n");
	e = getFront(DQ);		displayDeque(DQ);
	if (e != ERROR)	printf("front ������: %d\n", e);
	printf("\n== rear �˻�==\n");
	e = getRear(DQ);		displayDeque(DQ);
	if (e != ERROR)	printf("rear ������: %d\n", e);
	printf("\n== Deque ���� ==\n");
	clear(DQ);	displayDeque(DQ);

	return 0;
}

