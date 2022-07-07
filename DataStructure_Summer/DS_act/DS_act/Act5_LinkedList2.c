#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* llink, rlink;
}listNode;

typedef struct LinkedList {
	listNode* head;
	int length;
}linkedList;


void insertFirst(linkedList* L, element x)
{
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	if (L->head == NULL) {
		newNode->rlink = NULL;
		newNode->llink = NULL;
		L->head = newNode;
	}
	else {
		newNode->llink = NULL;
		newNode->rlink = L->head;
		newNode->rlink->llink = newNode; 
		// newNode의 rlink를 따라가면 
		//다음 노드가 나오는데, 거기서 llink에 
		//newNode 값을 넣는다.
		L->head = newNode;
		
	}
	L->length++;
}

void insertLast(linkedList* L, element x)
{
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	listNode* temp;
	newNode->data = x;
	newNode->rlink = NULL;
	if (L->head == NULL) {
		newNode->llink = NULL;
		L->head = newNode;
	}
	else {
		temp = L->head;
		while (temp->rlink != NULL) {
			temp = temp->rlink; 
			// 마지막 자리를 찾아주기
			// 마지막 자리의 rlink는 NULL일것이기 때문
		}
		newNode->llink = temp;
		temp->rlink = newNode;
	}
	L->length++;
}


void insert(linkedList* L, listNode* pre, element x)
{
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	if (L == NULL) {
		newNode->rlink = NULL;
		newNode->llink = NULL;
		L = newNode;//여기 L값 봐야됨

	}
	else if (pre == NULL) {
		newNode->llink = NULL;
		newNode->rlink = L;
		L = newNode;//여기도 봐야됨
		newNode->rlink->llink = newNode;
	}
	else {
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if (newNode->rlink != NULL) {
			newNode->rlink->llink = newNode;
		}
	}
	L->length++;
		
	
}


int delete (linkedList* L, listNode* p)
{
	if (L == NULL) {
		return false;
	}
	if (p == NULL) {
		return false;
	}
	if (p->llink == NULL) {
		L=p->rlink;
	}
	else {
		p->llink.rlink = p->rlink;
	}
	// 마저써야됨

}