#ifndef __LINKED_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define ERROR 123456789
#define TRUE 1
#define FALSE 0
 
typedef int element;

// Queue�� ��� ������ ����ü�� ����
typedef struct QueueNode {
	element data;
	struct QueueNode* link;
}queueNode;

// Queue�� front, rear�� ǥ���� ����ü
typedef struct LinkedQueue {
	queueNode *front, *rear;
}Queue; 

Queue* create();					// ����ť ����
int isFull(Queue* Q);				// ť�� ��ȭ�������� Ȯ���ϴ� ����
int isEmpty(Queue* Q);				// ť�� ����������� Ȯ���ϴ� ����
void enqueue(Queue* Q, element x);	// ť�� rear�� ��Ҹ� �߰��ϴ� ����
element dequeue(Queue* Q);			// ť���� ���� ���� ����� ��� ���� �� ��ȯ�ϴ� ����
element peek(Queue* Q);				// ť���� ���� ���� ����� ��Ҹ� ��ȯ�ϴ� ����
void displayQueue(Queue* Q);		// ť�� ��� ��� ���
void clear(Queue* Q);				// ť ���� 

#endif



