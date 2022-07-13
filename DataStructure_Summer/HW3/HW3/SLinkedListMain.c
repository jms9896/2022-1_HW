#include <stdio.h>
#include "SLinkedList.h"

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)공백리스트 생성하기\n");
	// Fill your code
	L = initList(); // L 초기화
	displayList(L); // L 출력

	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));

	printf("\n(2)리스트에 10, 50, 80 노드를 순서대로 삽입하기\n");
	// Fill your code
	insertLast(L, 10);
	insertLast(L, 80);
	insertLast(L, 50);
	displayList(L);

	printf("리스트에 저장된 데이터 개수: %d\n", L->length);	
	printf("\n(3)리스트에서 50 노드 탐색하기\n");
	// Fill your code
	p = search(L, 50);
	if (p == NULL)
		printf("No Data\n");
	else
		printf("%d Find Data\n", p->data);

	printf("\n(4)50 노드 뒤에 60 노드 삽입하기\n");
	// Fill your code
	insert(L, p, 40);
	displayList(L);

	printf("리스트에 저장된 데이터 개수: %d\n", L->length);
	printf("\n(5)리스트에서 80 노드 삭제하기\n");
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
