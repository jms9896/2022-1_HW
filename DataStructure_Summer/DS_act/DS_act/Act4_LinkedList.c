// �������� �ҽ��ڵ�(.c) ����(.pdf)
// ���μ� 2015251165
// main�Լ��� �̸� �й� ����
// ������ �ڵ� ������ ����
// �ҽ��ڵ��̸� homework1(������ȣ).c �����̸� 2015251165_���μ�_1(������ȣ).pdf

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
	// ���� �պ��ߵ�
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	// �� �ص� �� listNode* temp = (listNode*)malloc(sizeof(listNode));
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
	// ���������
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

