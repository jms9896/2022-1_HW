#include <stdio.h>
#define MAX_SIZE 7;


typedef int HData;
typedef struct {
	HData heap[MAX_SIZE];
	int numOfData;
}Heap;

void insertHeap(Heap* h, HData x)
{
	if (h->heap == MAX_SIZE) {
		error("overflow");
		return -1;
	}
	int idx = h->numOfData + 1;
	while (idx != 1) {
		if (x > h->heap((int)(idx / 2))) {
			h->heap[idx] = h->heap((int)idx / 2);
			idx = (int)(idx / 2);
		}
		else {
			break;
		}

	}
	else {
		h->head[idx] = x;
		h->numOfData++
	}
	// 에러수정해야됨
}

HData deleteHeap(Heap* h)
{
	if (isEmpty(h)) {
		error("underflow");
		return -1;

	}
	int item = h->heap[1];
	int lastVal = h->heap[h->numOfData];
	int parentIdx = 1;
	int childIdx = 2;
	
	while (childIdx <= h->numOfData) {
		if ((childIdx <= h->numOfData) && (h->heap[childIdx] < h->heap[childIdx + 1])) {
			childIdx++;

		}
		if (lastVal >= h->heap[childIdx]) {
			break;
		}
		else {
			h->heap[parentIdx]->h->heap[childIdx];
			parentIdx = childIdx;
			childIdx = childIdx * 2;
		}
	}
	h->heap[parentIdx] = lastVal;
	h->numOfData--;
	return item;

}
