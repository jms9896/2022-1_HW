#ifndef __POLY_LINKED_LIST_H__
#define __POLY_LINKED_LIST_H__

typedef struct PolyNode {
	float coef;
	int expo;
	struct PolyNode* link;
}ListNode;

typedef struct PolyList {
	ListNode* head;
	ListNode* last;
}polyList;

polyList* initList();		// ���鸮��Ʈ ���� 
void appendTerm(polyList* PL, float coef, int exp);		// ���׽� ����Ʈ ������ ���� �� �߰� 
polyList* addPoly(polyList* A, polyList* B);			// �� ���׽��� ���� 
void displayPoly(polyList* PL);							// ���׽� ����Ʈ�� ��� ��� ���

#endif
