#include <stdio.h>
#include "SLinkedList2.h"

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)���鸮��Ʈ �����ϱ�\n");
	// Fill your code
	L = initList();
	displayList(L);
	printf("Num of data in list: %d\n", L->length); 
	// ���̸� �˸� ���� �� �� ����

	
	printf("\n(2)����Ʈ�� ��, ȭ, �� ��带 ������� �����ϱ�\n");
	// Fill your code
	insertLast(L, "Mon");
	insertLast(L, "Tue");
	insertLast(L, "Thur");
	displayList(L);
	printf("Num of data in list: %d\n", L->length);

	printf("\n(3)�� ��� �ڿ� �� ��� �����ϱ�\n");
	// Fill your code
	p = search(L, "Thur");
	if (p == NULL) { //search �ȵ�����
		printf("No searched data\n");
	}
	else {
		printf("%s \n", p->data);
		insert(L, p, "Sun");
	}
	displayList(L);
	printf("Num of data in list: %d\n", L->length);


	 
	printf("\n(4)����Ʈ���� �� ��� Ž���ϱ�\n");
	// Fill your code
	// search�Լ� �̿�
	p = search(L, "Wed");
	if (p == NULL) {
		printf("No searched data\n");
	}
	else {
		printf("%s \n", p->data);
	}
	displayList(L);
	printf("Num of data in list: %d\n", L->length);



	
	printf("\n(5)����Ʈ ������ �������� �ٲٱ�\n");
	// Fill your code
	reverse(L);
	displayList(L);
	printf("Num of data in list: %d\n", L->length);

	
	clear(L);

	return 0;
}

