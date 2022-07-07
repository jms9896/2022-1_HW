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
		// newNode�� rlink�� ���󰡸� 
		//���� ��尡 �����µ�, �ű⼭ llink�� 
		//newNode ���� �ִ´�.
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
			// ������ �ڸ��� ã���ֱ�
			// ������ �ڸ��� rlink�� NULL�ϰ��̱� ����
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
		L = newNode;//���� L�� ���ߵ�

	}
	else if (pre == NULL) {
		newNode->llink = NULL;
		newNode->rlink = L;
		L = newNode;//���⵵ ���ߵ�
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
	// ������ߵ�

}