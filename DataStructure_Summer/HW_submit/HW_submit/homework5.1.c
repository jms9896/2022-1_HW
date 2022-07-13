//2015251165 ���μ�
#pragma once
//#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

#define MAX_SIZE 100
#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Stack�� ����ü�� ����
typedef struct ArrayStack {
	element stack[MAX_SIZE];
	int top;
}Stack;

Stack* create();					// ���齺�� ����
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
//#include "ArrayStack.h"

// ���齺�� ����
Stack* create() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = -1;
	return S;
}

// ������ ��ȭ�������� Ȯ���ϴ� ����					
int isFull(Stack* S) {
	// Fill your code
	if (S->top == MAX_SIZE - 1) {
		return 1;
	}
	else
		return 0;
}

// ������ ����������� Ȯ���ϴ� ����			
int isEmpty(Stack* S) {
	// Fill your code
	if (S->top == -1) {
		return 1;
	}
	else
		return 0;

}

// ������ top�� ��Ҹ� �߰��ϴ� ����			
void push(Stack* S, element x) {
	// Fill your code
	if (isFull(S)) {
		printf("stack full\n");
	}
	else {
		S->top = S->top + 1;
		S->stack[S->top] = x; 
	}
}

// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����	
element pop(Stack* S) {
	// Fill your code
	if (isEmpty(S)) { // �˻�
		printf("stack empty\n");
		return -1;
	}
	else { // ž -1 �ϰ� e ��ȯ
		element e = S->stack[S->top];
		S->top -= 1;
		printf("%d del\n", e);
		return e; 
	}


}

// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����			
element peek(Stack* S) {
	// Fill your code
	if (isEmpty(S)) {
		printf("stack empty\n");
		return -1;
	}
	else {
		printf("saved in top: %d\n", S->stack[S->top]);
		return S->stack[S->top];
	}
}

// ������ ��� ��� ��� 			
void displayStack(Stack* S) {
	int i;
	printf("STACK [ ");
	for (i = 0; i <= S->top; i++)
		printf("%d ", S->stack[i]);
	printf(" ]\ttop: %d\n", S->top);
}

// ���� ����
void clear(Stack* S) {
	S->top = -1;
}

#include <stdio.h>
#include <stdlib.h>

//#include "ArrayStack.h"

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
	displayStack(S);
	push(S, 20);
	displayStack(S);
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
	//pop(S);
	//displayStack(S);


	//printf("\n(4-2) ���ÿ��� ��� ����\n");
	//pop(S);
	//displayStack(S);


	//printf("\n(4-3) ���ÿ��� ��� ����\n");
	//pop(S);
	//displayStack(S);


	//printf("\n(4-4) ���ÿ��� ��� ����\n");
	//pop(S);
	//displayStack(S);


	printf("\n(5) ���� ����\n");
	clear(S);
	displayStack(S);

	return 0;
}
