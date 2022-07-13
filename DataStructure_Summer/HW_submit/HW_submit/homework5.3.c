//2015251165 정민성
#pragma once
//#ifndef __LINKED_STACK_H__
#define __LINKED_STACK_H__

#define ERROR 123456789
#define TRUE 1
#define FALSE 0
#include <string.h>

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
//#include "ArrayStack.h"		// 배열로 구현한 스택 이용시 주석 해제
//#include "LinkedStack.h"		// 연결리스트로 구현한 스택 이용시 주석 해제 

int testPair(char* exp) {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S = create();
	char symbol, lparen;
	int i, length = strlen(exp);

	// Fill your code
	for (i = 0; i < length; i++) { // 1부터 끝까지
		symbol = exp[i]; 
		switch (symbol)
		{ //좌괄호
		case '(':
		case '[':
		case '{':
			push(S, symbol);
			break;
			//우괄호
		case ')':
		case ']':
		case '}':
			if (S->top == NULL)
				return 0;
			else
			{
				// 최상단 스택 읽기
				lparen = pop(S);
				// pair 확인
				if ((lparen == '(' && symbol != ')') ||
					(lparen == '[' && symbol != ']') ||
					(lparen == '{' && symbol != '}'))
					//pair 안맞으면 탈출
					return 0;
				//페어 맞아도 탈출
				else break;
			}
		}
	}
	// 페어 체크
	if (S->top == NULL)
		return 1;
	// 페어 안맞는 오류 0으로 탈출
	else
		return 0;

}

int main() {
	int i;
	char* x[4] = { "(A - B) * C) + D", "(A - B) * C + ( D", "A [ B ( C ] )", "{A / (B - C)}" };

	for (i = 0; i < 4; i++) {
		printf("%s ", x[i]);
		if (testPair(x[i]))
			printf("-> 수식의 괄호가 올바르게 사용되었습니다!\n");
		else
			printf("-> 수식의 괄호가 틀렸습니다!\n");
	}

	return 0;
}
