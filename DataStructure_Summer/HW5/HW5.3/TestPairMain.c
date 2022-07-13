#include <stdio.h>
#include <stdlib.h>
//#include "ArrayStack.h"		// �迭�� ������ ���� �̿�� �ּ� ����
#include "LinkedStack.h"		// ���Ḯ��Ʈ�� ������ ���� �̿�� �ּ� ���� 

int testPair(char* exp) {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S = create();
	char symbol, lparen;
	int i, length = strlen(exp);

	// Fill your code
	for (i = 0; i < length; i++) {
		symbol = exp[i];
		switch (symbol)
		{
			// 1. insert left parenthesis 
		case '(':
		case '[':
		case '{':
			push(S, symbol);
			break;
			// 2. read right parenthesis 
		case ')':
		case ']':
		case '}':
			if (S->top == NULL)
				return 0;
			else
			{
				// 2-1. read top paren from stack
				lparen = pop(S);
				// 2-2. check pair
				if ((lparen == '(' && symbol != ')') ||
					(lparen == '[' && symbol != ']') ||
					(lparen == '{' && symbol != '}'))
					//2-3. if pair wrong, error
					return 0;
				//2-4 if pair correct, check next symbol
				else break;
			}
		}
	}
	// finish check pair normally
	if (S->top == NULL)
		return 1;
	// if not NULL(wrong paren) return '0'
	else
		return 0;

}

int main() {
	int i;
	char* x[4] = {"(A - B) * C) + D", "(A - B) * C + ( D", "A [ B ( C ] )", "{A / (B - C)}"};
	
	for(i=0; i<4; i++) {
		printf("%s ", x[i]);
		if(testPair(x[i]))
			printf("-> ������ ��ȣ�� �ùٸ��� ���Ǿ����ϴ�!\n");
		else
			printf("-> ������ ��ȣ�� Ʋ�Ƚ��ϴ�!\n");
	}
	
	return 0;
}
