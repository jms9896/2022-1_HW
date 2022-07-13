#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

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
element deleteFront(Deque* DQ) {
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
element deleteRear(Deque* DQ) {
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

		if (DQ->front == NULL){
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
	while(p) {
		printf("%d ", p->data);
		p = p->rlink;
	}
	printf(" ]\n");
}

// �� ���� 	
void clear(Deque* DQ) {
	dequeNode* p;
	while(DQ->front) {
		p = DQ->front;
		DQ->front = DQ->front->rlink;
		free(p);
		p = NULL;
	}
}				
