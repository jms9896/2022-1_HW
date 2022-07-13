#ifndef __S_LINKED_LIST2_H__
#define __S_LINKED_LIST2_H__

#define TRUE 1
#define FALSE 0

typedef int element;	// Require modification

// �ܼ����Ḯ��Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode {
	element data;
	struct ListNode* link;
}listNode;

// ����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct LinkedList {
	listNode* head;
	int length;
}linkedList;

linkedList* initList();		// ���鸮��Ʈ ���� 
void insert(linkedList* L, listNode* pre, element x);	// �߰� ���� ���� 
void insertFirst(linkedList* L, element x);				// ù ��° ���� ���� 
void insertLast(linkedList* L, element x);				// ������ ���� ���� 
int delete(linkedList* L, listNode* p);					// ��� ���� 
listNode* search(linkedList* L, element x);				// �˻� 
int getLength(linkedList* L);							// ����Ʈ�� ����Ǿ� �ִ� �������� �� ��ȯ 
void displayList(linkedList* L);						// ����Ʈ�� ��� ��� ��� 
void clear(linkedList* L);								// ����Ʈ�� ��ü �޸� ���� 
void reverse(linkedList* L);							// ����Ʈ�� ��� ������ �������� �ٲ� 

#endif
