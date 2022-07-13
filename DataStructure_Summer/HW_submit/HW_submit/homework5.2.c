//2015251165 ���μ�
#pragma once
//#ifndef __LINKED_STACK_H__
#define __LINKED_STACK_H__

#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Stack�� ��� ������ ����ü�� ����
typedef struct StackNode {
	element data;
	struct StackNode* link;
}stackNode;

// Stack�� ������ ���(���� �ֱٿ� ���Ե� ���)�� ��Ÿ���� top�� ����ü�� ���� 
typedef struct LinkedStack {
	stackNode* top;
}Stack;

Stack* create();					// ���齺�� ����
int getLength(Stack* S);			// ���ÿ� ����� ��� ������ ��ȯ�ϴ� ���� 
int isFull(Stack* S);				// ������ ��ȭ�������� Ȯ���ϴ� ����
int isEmpty(Stack* S);				// ������ ����������� Ȯ���ϴ� ����
void push(Stack* S, element x);		// ������ top�� ��Ҹ� �߰��ϴ� ����
element pop(Stack* S);				// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����
element peek(Stack* S);				// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����
void displayStack(Stack* S);		// ������ ��� ��� ���
void clear(Stack* S);				// ���� ���� 

//#endif


#include <stdio.h>
#include <stdlib.h>
//#include "LinkedStack.h"

// ���齺�� ����
Stack* create() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = NULL;
	return S;
}

// ������ ��ȭ�������� Ȯ���ϴ� ����					
int isFull(Stack* S) {
	// Fill your code
	return 0;
}

// ������ ����������� Ȯ���ϴ� ����			
int isEmpty(Stack* S) {
	// Fill your code
	if (S->top == NULL) {
		return 1;
	}
	else
		return 0;
	//return S->top == NULL;

}

// ������ top�� ��Ҹ� �߰��ϴ� ����			
void push(Stack* S, element x) {
	// Fill your code
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->data = x;
	newNode->link = S->top;
	S->top = newNode;
}

// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����	
element pop(Stack* S) {
	// Fill your code
	stackNode* t;
	element n;
	if (isEmpty(S)) { // ���� ����
		printf("Stack is empty\n");
		return -1;
	}
	else {
		t = S->top;
		n = t->data; // ��
		printf("%d del\n", n); // ���
		S->top = t->link; 
		free(t); //�޸� ����
		return n;
	}

}

// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����			
element peek(Stack* S) {
	// Fill your code
	printf("empty\n");
	return -1;
}

// ������ ��� ��� ��� 			
void displayStack(Stack* S) {
	stackNode* p = S->top;
	printf("STACK [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// ���� ����
void clear(Stack* S) {
	stackNode* p;
	while (S->top) {
		p = S->top;
		S->top = S->top->link;
		free(p);
		p = NULL;
	}
}


#include <stdio.h>
//#include "LinkedStack.h"

int main() {
	Stack* S;
	element item;
	int i;

	printf("(1) ���� ���� �����ϱ�\n");
	S = create();
	displayStack(S);

	printf("\n(2) ���ÿ� 10, 20, 30�� ���ʷ� ����\n");
	// Fill your code
	push(S, 10);
	push(S, 20);
	push(S, 30);
	displayStack(S);



	printf("\n(3) ���� top�� ��Ҹ� ���\n");
	// Fill your code
	peek(S);
	displayStack(S);


	// Fill your code
	for (int i = 1; i <= 4; i++) {
		printf("\n(4-%d) ���ÿ��� ��� ����\n", i);
		pop(S);
		displayStack(S);


	}
	//printf("\n(4-1) ���ÿ��� ��� ����\n");


	//printf("\n(4-2) ���ÿ��� ��� ����\n");


	//printf("\n(4-3) ���ÿ��� ��� ����\n");


	//printf("\n(4-4) ���ÿ��� ��� ����\n");


	displayStack(S);


	printf("\n(5) ���� ����\n");
	clear(S);
	displayStack(S);

	return 0;
}

