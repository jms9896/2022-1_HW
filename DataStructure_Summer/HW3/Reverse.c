#include <stdio.h>
#include <stdlib.h>
#include "Reverse.h"

// 리스트의 노드 순서를 역순으로 바꾸는 연산
void reverse(linkedList_h* L) {
	listNode* p;
	listNode* q;
	listNode* r;

	p = L->head;		// 포인터 p를 첫 번째 노드에 설정
	q = NULL;
	r = NULL;

	// 리스트의 첫 번째 노드부터 링크를 따라 다음 노드로 이동하면서 
	// 노드 간의 연결을 바꿈
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	L->head = q;
}

#endif