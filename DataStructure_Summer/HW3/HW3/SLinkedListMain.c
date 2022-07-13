#include <stdio.h>
#include "SLinkedList.h"

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)���鸮��Ʈ �����ϱ�\n");
	// Fill your code
	L = initList(); // L �ʱ�ȭ
	displayList(L); // L ���

	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));

	printf("\n(2)����Ʈ�� 10, 50, 80 ��带 ������� �����ϱ�\n");
	// Fill your code
	insertLast(L, 10);
	insertLast(L, 80);
	insertLast(L, 50);
	displayList(L);

	printf("����Ʈ�� ����� ������ ����: %d\n", L->length);	
	printf("\n(3)����Ʈ���� 50 ��� Ž���ϱ�\n");
	// Fill your code
	p = search(L, 50);
	if (p == NULL)
		printf("No Data\n");
	else
		printf("%d Find Data\n", p->data);

	printf("\n(4)50 ��� �ڿ� 60 ��� �����ϱ�\n");
	// Fill your code
	insert(L, p, 40);
	displayList(L);

	printf("����Ʈ�� ����� ������ ����: %d\n", L->length);
	printf("\n(5)����Ʈ���� 80 ��� �����ϱ�\n");
	// Fill your code
	p = search(L, 80);
	if (delete(L, p))
		printf("Del success!\n");
	else
		printf("Del fail!\n");
	displayList(L);
	printf("Num of Data in list: %d\n", getLength(L));



	
	clear(L);

	return 0;
}
