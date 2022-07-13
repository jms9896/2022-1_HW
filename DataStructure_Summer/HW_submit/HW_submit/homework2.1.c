//2015251165 ���μ�
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100		// �迭�� �ִ� ũ��

typedef int element;
typedef struct {
	element list[MAX_SIZE];	// �迭 ����
	int length;		// ���� �迭�� ����� �ڷ���� ����
}ArrayListType;

// ���� ó�� �Լ�nnnn
void error(char *message)
{
	printf("%s\n", message);
}

// ����Ʈ �ʱ�ȭ
void init(ArrayListType *L)
{
	L->length = 0;
}

// �� ����Ʈ �˻�
// ����Ʈ�� ��� ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
int isEmpty(ArrayListType *L)
{
	return L->length == 0;
}

// ����Ʈ�� ��ȭ������ �˻�
// ����Ʈ�� ������ ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
int isFull(ArrayListType *L)
{
	return L->length == MAX_SIZE;
}

// ����Ʈ�� ��� ��� ���
void display(ArrayListType *L)
{
	int i;
	printf("===Print Lists===\n");
	for (i=0; i<L->length; i++)
		printf("ArrayList[%d]: %d\n", i, L->list[i]);
}

// ���� �Լ� 
// pos: �����ϰ��� �ϴ� ��ġ
// item: �����ϰ��� �ϴ� �ڷ�
void insert(ArrayListType *L, int pos, element item)
{
	// Fill your code
	if (isFull(L)) { 
		// ����Ʈ ���� ���� ����
		error("List is Full!");

	}
	else if ((pos < 0) || (pos > L->length)) {
		// �������� ��ġ�� 0���� �۰ų�, ����Ʈ �� �������� ũ�� ����
		error("Index Error");
	}
	else {
		for (int i = (L->length - 1); i >= pos; i--) {
			// �� �� �ִ°� �ƴϱ� ������ length-1���� ����
			L->list[i + 1] = L->list[i];
			// ����Ʈ�� �ڿ������� �� ĭ�� �о �ֱ�
		}
		L->list[pos] = item;
		// ����Ʈ ���� ��ġ ������ ��忡 ���� ����
		L->length++;
		// ����Ʈ ũ�⸦ 1 ����������.
		// ����ũ��� �����̳�, ����Ʈ �� ������ ũ�⸦ �� �� �ִ� �����.
		printf("ArrayList[%d]�� %d ����\n", pos, item);
		//����Ʈ ���� �޽��� ���
	}
	
	// �Ϸ�

}

// ����Ʈ �� �տ� ��� ����
void insertFirst(ArrayListType *L, element item)
{
	// Fill your code
	if (isFull(L)) { // ����Ʈ �� �������� ���� ���
		error("List is Full!");

	}

	else {
		for (int i = (L->length - 1); i >= 0; i--) {
			//����Ʈ�� �ڿ������� 1�� �ٿ��ִµ�, ������ �ļ�
			L->list[i + 1] = L->list[i];
			//����Ʈ �� �ڿ����� �� ĭ�� �ڷ� �о��ֱ�
		}
		L->list[0] = item;
		//���� 0��°(ù��°)�� ������ ����
		L->length++;
		//����Ʈ ũ�⸦ �÷���� �� ���������� ����Ʈ�� ��Ȯ�� ũ�⸦ �� �� ����
		printf("ArrayList[%d]�� %d ����\n", 0, item);
		//����Ʈ ���� �޽��� ���
	}
	// �Ϸ�

}

// ����Ʈ �� ���� ��� ����
void insertLast(ArrayListType *L, element item)
{
	// Fill your code
	if (isFull(L)) { //����Ʈ �� ���� �� �����ϱ�
		error("List is Full!");

	}

	else {
		L->list[L->length] = item;
		// length�� ����Ʈ ���� �������̹Ƿ�, �ش� ��ġ�� �� ����
		L->length++;
		printf("ArrayList[%d]�� %d ����\n", L->length, item);
	}
	//�Ϸ�
}

// ���� �Լ�
// pos: �����ϰ��� �ϴ� ��ġ
// ��ȯ��: �����Ǵ� �ڷ�
element delete_(ArrayListType *L, int pos)
{
	// Fill your code
	element item;
	if (isEmpty(L)) { //�������ϴµ� �󸮽�Ʈ�� ������ϱ� ����
		error("List is Empty!");
	}
	else if ((pos < 0) || (pos >= L->length)) {
		//���� ��ġ �̻��ϸ� ����
		error("Index Error");
	}
	else {
		item = L->list[pos];
		//�ϴ� ������� ��ġ�� ���� ����ϰ�
		for (int i = pos; i < L->length - 1; i++) {
			/*������� ��ġ(pos)���� ���̿� - 1���� i�� ����.
			�ֳ��ϸ� length�� �������������ε�, 
			�̰� ������ �����ϱ⶧���� �̵��� i+1�� ���� ����.
			i+1�ϸ� length�� length-1 �ϴ°�*/
			L->list[i] = L->list[i + 1];
		}
		L->length--;
		printf("ArrayList[%d]�� %d ����\n", pos, item);
		return item;
	}
	// �Ϸ�
}

// ����Ʈ�� ��� ��� ����
void clear(ArrayListType *L)
{
	// Fill your code
	for (int i = 0; i <= L->length; i++) {
		L->list[0] = NULL;
		// �׳� ����Ʈ ���̸� 0���� ���ָ� �����ּڰ� �����ִϱ� clear
	}
	printf("ArrayList Clear\n");
	//�Ϸ�
	
}

// pos ��ġ�� ��Ҹ� item���� ��ü
void replace(ArrayListType *L, int pos, element item)
{
	// Fill your code
	L->list[pos] = item;
	// �ش� ��ġ ��� �����Ͱ��� �ٲ��ֱ�
	printf("ArrayList[%d]�� %d ��ü\n", pos, item);

	//�Ϸ�
}


int main()
{
	ArrayListType* plist;

	// ListType�� �������� �����ϰ� ListType�� ����Ű�� 
	// �����͸� �Լ��� �Ķ���ͷ� �����Ѵ�.
	plist = (ArrayListType *)malloc(sizeof(ArrayListType));
	init(plist);
	insert(plist, 0, 10);
	insert(plist, 0, 20);
	insertFirst(plist, 5);
	insertLast(plist, 30);
	insert(plist, -1, 3);
	display(plist);
	
	delete_(plist, 2);
	display(plist);
	
	replace(plist, 1, 50);
	display(plist);
	free(plist);

	return 0;
}
