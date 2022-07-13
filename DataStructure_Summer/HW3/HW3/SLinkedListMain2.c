#include <stdio.h>
#include "SLinkedList2.h"

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)공백리스트 생성하기\n");
	// Fill your code
	L = initList();
	displayList(L);
	printf("Num of data in list: %d\n", L->length); 
	// 길이만 알면 개수 알 수 있음

	
	printf("\n(2)리스트에 월, 화, 목 노드를 순서대로 삽입하기\n");
	// Fill your code
	insertLast(L, "Mon");
	insertLast(L, "Tue");
	insertLast(L, "Thur");
	displayList(L);
	printf("Num of data in list: %d\n", L->length);

	printf("\n(3)목 노드 뒤에 일 노드 삽입하기\n");
	// Fill your code
	p = search(L, "Thur");
	if (p == NULL) { //search 안됐으니
		printf("No searched data\n");
	}
	else {
		printf("%s \n", p->data);
		insert(L, p, "Sun");
	}
	displayList(L);
	printf("Num of data in list: %d\n", L->length);


	 
	printf("\n(4)리스트에서 수 노드 탐색하기\n");
	// Fill your code
	// search함수 이용
	p = search(L, "Wed");
	if (p == NULL) {
		printf("No searched data\n");
	}
	else {
		printf("%s \n", p->data);
	}
	displayList(L);
	printf("Num of data in list: %d\n", L->length);



	
	printf("\n(5)리스트 순서를 역순으로 바꾸기\n");
	// Fill your code
	reverse(L);
	displayList(L);
	printf("Num of data in list: %d\n", L->length);

	
	clear(L);

	return 0;
}

