//2015251165 ���μ�
#pragma once
//#ifndef __LINKED_STACK_H__
#define __LINKED_STACK_H__

#define ERROR 123456789
#define TRUE 1
#define FALSE 0
#include <string.h>

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
//#include "ArrayStack.h"		// �迭�� ������ ���� �̿�� �ּ� ����
//#include "LinkedStack.h"		// ���Ḯ��Ʈ�� ������ ���� �̿�� �ּ� ���� 

int testPair(char* exp) {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S = create();
	char symbol, lparen;
	int i, length = strlen(exp);

	// Fill your code
	for (i = 0; i < length; i++) { // 1���� ������
		symbol = exp[i]; 
		switch (symbol)
		{ //�°�ȣ
		case '(':
		case '[':
		case '{':
			push(S, symbol);
			break;
			//���ȣ
		case ')':
		case ']':
		case '}':
			if (S->top == NULL)
				return 0;
			else
			{
				// �ֻ�� ���� �б�
				lparen = pop(S);
				// pair Ȯ��
				if ((lparen == '(' && symbol != ')') ||
					(lparen == '[' && symbol != ']') ||
					(lparen == '{' && symbol != '}'))
					//pair �ȸ����� Ż��
					return 0;
				//��� �¾Ƶ� Ż��
				else break;
			}
		}
	}
	// ��� üũ
	if (S->top == NULL)
		return 1;
	// ��� �ȸ´� ���� 0���� Ż��
	else
		return 0;

}

int main() {
	int i;
	char* x[4] = { "(A - B) * C) + D", "(A - B) * C + ( D", "A [ B ( C ] )", "{A / (B - C)}" };

	for (i = 0; i < 4; i++) {
		printf("%s ", x[i]);
		if (testPair(x[i]))
			printf("-> ������ ��ȣ�� �ùٸ��� ���Ǿ����ϴ�!\n");
		else
			printf("-> ������ ��ȣ�� Ʋ�Ƚ��ϴ�!\n");
	}

	return 0;
}
