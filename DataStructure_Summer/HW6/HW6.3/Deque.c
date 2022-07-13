#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

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

// 덱의 꼬리에 위치한 요소 삭제 및 반환하는 연산 		
element deleteRear(Deque* DQ) {
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
	while(p) {
		printf("%d ", p->data);
		p = p->rlink;
	}
	printf(" ]\n");
}

// 덱 비우기 	
void clear(Deque* DQ) {
	dequeNode* p;
	while(DQ->front) {
		p = DQ->front;
		DQ->front = DQ->front->rlink;
		free(p);
		p = NULL;
	}
}				
