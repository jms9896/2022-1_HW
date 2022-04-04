#include <stdio.h>


//항목 타입은 엘레멘트
typedef int element;
typedef struct ListNode {
	element data; //list노드의 data field
	struct ListNode* list; //list노드의 link field
}listNode;

typedef struct LinkedList {
	listNode* head; //리스트의 첫 번째 항목 변수
	int length; // 리스트 항목 개수
}linkedList;

//공백리스트 생성
linkedList* initList{
	linkedList * L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	return L;
}

// int getLength() 연산
int getLength(linkedList* L) {
	return L->length;
}
/* insert 알고리즘
void insert(linkedList* L, listNode* pre, element x)
{
	insert(L, pre, x)
		newNode.data<- x
		if (L = NULL) then
			newNode.link <- NULL
			L<-newNode
		else if(pre = NULL) then
			newNode.link <- L
			L <- newNode
		else
			newNode.link <- pre.link
			pre.link <- newNode
		endif
		length++
	end insert()


}
*/
void insert(linkedList* L, listNode* pre, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;

	if (L->head == NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) {
		newNode->link = L->head;
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
	L->length++;
}

//첫 번째 노드로 삽입
void insertFirst(linkedList* L, element x) {
	listNode* newNode;
	newNode* (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	newNode->link = L->head;
	L->length++;
}

//마지막 노드로 삽입
void insertLastNode(linkedList* L, element x) {
	listNode* newNode, * temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	newNode->link = NULL;

	if (L->head == NULL) {
		L->head = newNode;
	}
	else {
		temp = L->head;
		while (temp->link != NULL) {
			temp->link = newNode;
		}
	}
	L->length++
}




int main(void)
{

	return 0;
}