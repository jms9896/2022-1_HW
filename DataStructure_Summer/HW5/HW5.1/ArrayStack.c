#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

// ���齺�� ����
Stack* create() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = -1;
	return S;
}

// ������ ��ȭ�������� Ȯ���ϴ� ����					
int isFull(Stack* S) {
	// Fill your code
}

// ������ ����������� Ȯ���ϴ� ����			
int isEmpty(Stack* S) {
	// Fill your code

}

// ������ top�� ��Ҹ� �߰��ϴ� ����			
void push(Stack* S, element x) {
	// Fill your code


}

// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����	
element pop(Stack* S) {
	// Fill your code

}

// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����			
element peek(Stack* S) {
	// Fill your code


}

// ������ ��� ��� ��� 			
void displayStack(Stack* S) {
	int i;
	printf("STACK [ "); 
	for(i=0; i<=S->top; i++)
		printf("%d ", S->stack[i]);
	printf(" ]\ttop: %d\n", S->top);
}

// ���� ����
void clear(Stack* S) {
	S->top = -1;
}				

