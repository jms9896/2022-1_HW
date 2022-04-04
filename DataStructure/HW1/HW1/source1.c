#include <stdio.h>


//�׸� Ÿ���� ������Ʈ
typedef int element;
typedef struct ListNode {
	element data; //list����� data field
	struct ListNode* list; //list����� link field
}listNode;

typedef struct LinkedList {
	listNode* head; //����Ʈ�� ù ��° �׸� ����
	int length; // ����Ʈ �׸� ����
}linkedList;

//���鸮��Ʈ ����
linkedList* initList{
	linkedList * L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	return L;
}

// int getLength() ����
int getLength(linkedList* L) {
	return L->length;
}
/* insert �˰���
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

//ù ��° ���� ����
void insertFirst(linkedList* L, element x) {
	listNode* newNode;
	newNode* (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	newNode->link = L->head;
	L->length++;
}

//������ ���� ����
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