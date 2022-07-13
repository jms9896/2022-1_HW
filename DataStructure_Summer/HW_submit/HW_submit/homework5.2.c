//2015251165 정민성
#pragma once
//#ifndef __LINKED_STACK_H__
#define __LINKED_STACK_H__

#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Stack의 노드 구조를 구조체로 정의
typedef struct StackNode {
	element data;
	struct StackNode* link;
}stackNode;

// Stack의 마지막 요소(가장 최근에 삽입된 노드)를 나타내는 top을 구조체로 정의 
typedef struct LinkedStack {
	stackNode* top;
}Stack;

Stack* create();					// 공백스택 생성
int getLength(Stack* S);			// 스택에 저장된 요소 개수를 반환하는 연산 
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
//#include "LinkedStack.h"

// 공백스택 생성
Stack* create() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = NULL;
	return S;
}

// 스택이 포화상태인지 확인하는 연산					
int isFull(Stack* S) {
	// Fill your code
	return 0;
}

// 스택이 공백상태인지 확인하는 연산			
int isEmpty(Stack* S) {
	// Fill your code
	if (S->top == NULL) {
		return 1;
	}
	else
		return 0;
	//return S->top == NULL;

}

// 스택의 top에 요소를 추가하는 연산			
void push(Stack* S, element x) {
	// Fill your code
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->data = x;
	newNode->link = S->top;
	S->top = newNode;
}

// 스택에서 마지막에 저장된 요소 삭제 및 반환하는 연산	
element pop(Stack* S) {
	// Fill your code
	stackNode* t;
	element n;
	if (isEmpty(S)) { // 공백 에러
		printf("Stack is empty\n");
		return -1;
	}
	else {
		t = S->top;
		n = t->data; // 팝
		printf("%d del\n", n); // 출력
		S->top = t->link; 
		free(t); //메모리 해제
		return n;
	}

}

// 스택에서 마지막에 저장된 요소를 반환하는 연산			
element peek(Stack* S) {
	// Fill your code
	printf("empty\n");
	return -1;
}

// 스택의 모든 요소 출력 			
void displayStack(Stack* S) {
	stackNode* p = S->top;
	printf("STACK [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// 스택 비우기
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

	printf("(1) 공백 스택 생성하기\n");
	S = create();
	displayStack(S);

	printf("\n(2) 스택에 10, 20, 30을 차례로 삽입\n");
	// Fill your code
	push(S, 10);
	push(S, 20);
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


	//printf("\n(4-2) 스택에서 요소 삭제\n");


	//printf("\n(4-3) 스택에서 요소 삭제\n");


	//printf("\n(4-4) 스택에서 요소 삭제\n");


	displayStack(S);


	printf("\n(5) 스택 비우기\n");
	clear(S);
	displayStack(S);

	return 0;
}

