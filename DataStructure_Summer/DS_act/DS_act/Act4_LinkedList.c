// 과제제출 소스코드(.c) 보고서(.pdf)
// 정민성 2015251165
// main함수에 이름 학번 적기
// 보고서에 코드 실행결과 포함
// 소스코드이름 homework1(과제번호).c 보고서이름 2015251165_정민성_1(과제번호).pdf

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}listNode;

typedef struct LinkedList {
	listNode* head;
	int length;
}linkedList;

void init(linkedList* L) {
	L->length = 0;
}
void insertFirst(linkedList* L, element x)
{
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	newNode->link = L->head;
	L->head = newNode;
	L->length++;
}

void insertLast(linkedList* L, element x)
{
	// 여긴 손봐야됨
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	// 안 해도 됨 listNode* temp = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	newNode->link = NULL;
	if (L->head == NULL) {
		L->head = newNode;
	}
	else {
		temp = L->head;
		while (temp->link != NULL) {
			temp = temp->link;
		}
		temp->link = newNode;
	}
	L->length++;
}

void insert(linkedList* L, listNode* pre, element x)
{
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
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

int delete_node(linkedList* L, listNode* p)
{
	// 마저써야함
	listNode* pre;
	if (L == NULL) {
		return false;
	}
	if (p == NULL) {
		return false;
	}
	if (L == p) {
		L = p->link;
		delete_node(p)
	}
}

int main(void)
{
	linkedList* root;
	root = initList();

	insertLast(root, 10);
	insertLast(root, 20);
	insertLast(root, 30);
	insertFirst(root, 0);

	//search hint
	listNode* pre;
	listNode* cur;
	pre = NULL;
	cur = root->head;

	while (cur != NULL) {
		if (cur->data == 20) {
			break;
		}
		else {
			pre = cur;
			cur = cur->link;
		}
	}
	displayList(root);
	printf("pre : %d // cur : %d\n", pre->data, cur->data);

	insert(root, pre, 40);
	delete(root, pre);
	displayList(root);
	return 0;

}

