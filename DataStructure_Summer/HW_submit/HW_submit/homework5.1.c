//2015251165 정민성
#pragma once
//#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

#define MAX_SIZE 100
#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Stack을 구조체로 정의
typedef struct ArrayStack {
	element stack[MAX_SIZE];
	int top;
}Stack;

Stack* create();					// 공백스택 생성
int isFull(Stack* S);				// 스택이 포화상태인지 확인하는 연산
int isEmpty(Stack* S);				// 스택이 공백상태인지 확인하는 연산
void push(Stack* S, element x);		// 스택의 top에 요소를 추가하는 연산
element pop(Stack* S);				// 스택에서 마지막에 저장된 요소 삭제 및 반환하는 연산
element peek(Stack* S);				// 스택에서 마지막에 저장된 요소를 반환하는 연산
void displayStack(Stack* S);		// 스택의 모든 요소 출력
void clear(Stack* S);				// 스택 비우기 

//#endif

#include <stdio.h>
#include <stdlib.h>
//#include "ArrayStack.h"

// 공백스택 생성
Stack* create() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = -1;
	return S;
}

// 스택이 포화상태인지 확인하는 연산					
int isFull(Stack* S) {
	// Fill your code
	if (S->top == MAX_SIZE - 1) {
		return 1;
	}
	else
		return 0;
}

// 스택이 공백상태인지 확인하는 연산			
int isEmpty(Stack* S) {
	// Fill your code
	if (S->top == -1) {
		return 1;
	}
	else
		return 0;

}

// 스택의 top에 요소를 추가하는 연산			
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

// 스택에서 마지막에 저장된 요소 삭제 및 반환하는 연산	
element pop(Stack* S) {
	// Fill your code
	if (isEmpty(S)) { // 검사
		printf("stack empty\n");
		return -1;
	}
	else { // 탑 -1 하고 e 반환
		element e = S->stack[S->top];
		S->top -= 1;
		printf("%d del\n", e);
		return e; 
	}


}

// 스택에서 마지막에 저장된 요소를 반환하는 연산			
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

// 스택의 모든 요소 출력 			
void displayStack(Stack* S) {
	int i;
	printf("STACK [ ");
	for (i = 0; i <= S->top; i++)
		printf("%d ", S->stack[i]);
	printf(" ]\ttop: %d\n", S->top);
}

// 스택 비우기
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

	printf("(1) 공백 스택 생성하기\n");
	S = create();
	displayStack(S);

	printf("\n(2) 스택에 10, 20, 30을 차례로 삽입\n");
	// Fill your code
	push(S, 10);
	displayStack(S);
	push(S, 20);
	displayStack(S);
	push(S, 30);
	displayStack(S);

	printf("\n(3) 현재 top의 요소를 출력\n");
	// Fill your code
	peek(S);
	displayStack(S);


	// Fill your code
	for (int i = 1; i <= 4; i++) {
		printf("\n(4-%d) 스택에서 요소 삭제\n", i);
		pop(S);
		displayStack(S);

	}
	//printf("\n(4-1) 스택에서 요소 삭제\n");
	//pop(S);
	//displayStack(S);


	//printf("\n(4-2) 스택에서 요소 삭제\n");
	//pop(S);
	//displayStack(S);


	//printf("\n(4-3) 스택에서 요소 삭제\n");
	//pop(S);
	//displayStack(S);


	//printf("\n(4-4) 스택에서 요소 삭제\n");
	//pop(S);
	//displayStack(S);


	printf("\n(5) 스택 비우기\n");
	clear(S);
	displayStack(S);

	return 0;
}
