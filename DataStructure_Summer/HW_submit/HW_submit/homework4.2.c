//2015251165 정민성
#pragma once
//#ifndef __POLY_LINKED_LIST_H__
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

polyList* initList();		// 공백리스트 생성 
void appendTerm(polyList* PL, float coef, int exp);		// 다항식 리스트 마지막 노드로 항 추가 
polyList* addPoly(polyList* A, polyList* B);			// 두 다항식의 덧셈 
void displayPoly(polyList* PL);							// 다항식 리스트의 모든 요소 출력

//#endif


#include <stdio.h>
#include <stdlib.h>
//#include "PolyList.h"

polyList* initList() {
	polyList* PL = (polyList*)malloc(sizeof(polyList));
	PL->head = NULL;
	PL->last = NULL;
	return PL;
}

void appendTerm(polyList* L, float coef, int expo) {
	// Fill your code
	ListNode* newNode; // 노드 만들어주기
	ListNode* p;
	newNode = (ListNode*)malloc(sizeof(ListNode)); // 메모리할당
	newNode->coef = coef; // 연결
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
			sum = pA->coef + pB->coef; // 같은경우 더해야됨
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
	for (; p; p = p->link) {
		printf("%3.0fx^%d", p->coef, p->expo);
		if (p->link != NULL)
			printf(" +");
	}
	printf("\n");
}


#include <stdio.h>
//#include "PolyList.h"

int main() {
	polyList* A = initList();
	polyList* B = initList();
	polyList* C = initList();

	// A(x) = 4x^3 + 3x^2 + 5x
	appendTerm(A, 4, 3);
	appendTerm(A, 3, 2);
	appendTerm(A, 5, 1);
	printf("A(x) = ");
	displayPoly(A);

	// B(x) = 3x^4 + x^3 + 2x + 1
	appendTerm(B, 3, 4);
	appendTerm(B, 1, 3);
	appendTerm(B, 2, 1);
	appendTerm(B, 1, 0);
	printf("B(x) = ");
	displayPoly(B);

	// C(x) = A(x) + B(x)
	C = addPoly(A, B);
	printf("C(x) = ");
	displayPoly(C);

	return 0;
}



