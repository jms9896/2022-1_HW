#include <stdio.h>
#include <stdlib.h>
#include "PolyList.h"

polyList* initList() {
	polyList* PL = (polyList*)malloc(sizeof(polyList));
	PL->head = NULL;
	PL->last = NULL;
	return PL;
}

void appendTerm(polyList* L, float coef, int expo) {
	// Fill your code
	ListNode* newNode;
	ListNode* p;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->coef = coef;
	newNode->expo = expo;
	newNode->link = NULL;
	if (L->head == NULL) {		
		L->head = newNode;
		return;
	}
	else {						
		p = L->head;
		while (p->link != NULL) {
			p = p->link;			
		}
		p->link = newNode;		
	}
}

polyList* addPoly(polyList* A, polyList* B) {
	polyList* C = initList();
	ListNode* pA = A->head;
	ListNode* pB = B->head;
	float sum;

	// Fill your code
	while (pA && pB) {
		// 다항식 A의 지수가 다항식 B의 지수와 같은 경우
		if (pA->expo == pB->expo) {
			sum = pA->coef + pB->coef;
			appendTerm(C, sum, pA->expo);
			pA = pA->link; pB = pB->link;
		}
		// 다항식 A의 지수가 다항식 B의 지수보다 큰 경우
		else if (pA->expo > pB->expo) {
			appendTerm(C, pA->coef, pA->expo);
			pA = pA->link;
		}
		// 다항식 A의 지수가 다항식 B의 지수보다 작은 경우
		else {
			appendTerm(C, pB->coef, pB->expo);
			pB = pB->link;
		}
	}
	// 다항식 A에 남아 있는 노드 복사
	for (; pA != NULL; pA = pA->link)
		appendTerm(C, pA->coef, pA->expo);

	// 다항식 B에 남아 있는 노드 복사
	for (; pB != NULL; pB = pB->link)
		appendTerm(C, pB->coef, pB->expo);
	return C;
}

void displayPoly(polyList* PL) {
	ListNode* p = PL->head;
	for(; p; p=p->link) {
		printf("%3.0fx^%d", p->coef, p->expo);
		if(p->link != NULL)
			printf(" +");
	}
	printf("\n");
}
