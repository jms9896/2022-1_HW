#include <stdio.h>
#include "SLinkedList.h"

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)공백리스트 생성하기\n");
	L = initList();
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));
	
	printf("\n(2)리스트에 10, 80, 50 노드를 순서대로 삽입하기\n");
	insertLast(L, 10);
	insertLast(L, 80);
	insertLast(L, 50);	
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));
	
	printf("\n(3)리스트에서 50 노드 탐색하기\n");
	p = search(L, 50);
	if(p == NULL)
		printf("찾는 데이터가 없습니다.\n");
	else
		printf("%d 노드를 찾았습니다\n", p->data);
	
	printf("\n(4)50 노드 뒤에 40 노드 삽입하기\n");
	insert(L, p, 40);
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));
	
	printf("\n(5)리스트에서 80 노드 삭제하기\n");
	p = search(L, 80);
	if(delete(L, p))
		printf("노드 삭제 성공!\n");
	else
		printf("노드 삭제 실패!\n");
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));
	
	clear(L);

	return 0;
}
