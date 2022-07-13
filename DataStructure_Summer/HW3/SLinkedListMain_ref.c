#include <stdio.h>
#include "SLinkedList.h"

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)���鸮��Ʈ �����ϱ�\n");
	L = initList();
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));
	
	printf("\n(2)����Ʈ�� 10, 80, 50 ��带 ������� �����ϱ�\n");
	insertLast(L, 10);
	insertLast(L, 80);
	insertLast(L, 50);	
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));
	
	printf("\n(3)����Ʈ���� 50 ��� Ž���ϱ�\n");
	p = search(L, 50);
	if(p == NULL)
		printf("ã�� �����Ͱ� �����ϴ�.\n");
	else
		printf("%d ��带 ã�ҽ��ϴ�\n", p->data);
	
	printf("\n(4)50 ��� �ڿ� 40 ��� �����ϱ�\n");
	insert(L, p, 40);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));
	
	printf("\n(5)����Ʈ���� 80 ��� �����ϱ�\n");
	p = search(L, 80);
	if(delete(L, p))
		printf("��� ���� ����!\n");
	else
		printf("��� ���� ����!\n");
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));
	
	clear(L);

	return 0;
}
