#include <stdio.h>
#include "LinkedStack.h"

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
		printf("\n(4-%d) ���ÿ��� ��� ����\n",i);
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

