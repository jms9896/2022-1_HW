//과제이름 번호, 문제번호, 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100


typedef int element;
typedef struct {
	element list[MAX_SIZE];
	int length;
}ArrayListType;

void init(ArrayListType* L) {
	L->length = 0;
}

int isEmpty(ArrayListType* L) {
	return L->length == 0;
}

int isFull(ArrayListType* L) {
	return L->length == MAX_SIZE;
}

void insert(ArrayListType* L, int pos, element item) {
	int i;
	if (isFull(L)) {
		error("List is Full!");

	}
	else if ((pos < 0) || (pos > L->length)) {
		error("Index Error");
	}
	else {
		for (i = (L->length - 1); i >= pos; i--) {
			L->list[i + 1] = L->list[i];
		}
		L->list[pos] = item;
		L->length++;

	}
}

element delete(ArrayListType* L, int pos) {
	int i;
	element item;
	if (isEmpty(L)) {
		error("List is Empty!");
	}
	else if ((pos < 0) || (pos >= L->length)) {
		error("Index Error");
	}
	else {
		item = L->list[pos];
		for (i = pos; i < L->length - 1; i++) {
			L->list[i] = L->list[i + 1];
		}
		L->length--;
		return item;
	}
}

int main(void)
{
	ArrayListType* plist;
	plist = (ArrayListType*)malloc(sizeof(ArrayListType) * 1);
	init(plist);
	printf(isEmpty(plist));
	insert(plist, 0, 10);
	insert(plist, 0, 50);
	insert(plist, 2, 30);
	//printf(plist);

	free(plist);

	return 0;
}