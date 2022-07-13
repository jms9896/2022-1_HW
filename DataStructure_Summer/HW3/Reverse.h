// #programa once

#ifndef _REVERSE_H_
#define _REVERSE_H_

#define TRUE 1
#define FALSE 0

typedef int element;	// Require modification

// 단순연결리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	element data;
	struct ListNode* link;
}listNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct LinkedList {
	listNode* head;
	int length;
}linkedList;

void reverse(linkedList* L);	