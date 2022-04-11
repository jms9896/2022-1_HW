#include "header.h"
# pragma warning (disable:"4996")

//���� �о����
void fileRead(linkedList* L, char* fileAddress) {
	FILE* fp;
	listData tmp;
	fp = fopen(fileAddress, "r");

	int countLine = 1;
	char fileTmp[50];

	//fputc �Լ� ���Ͽ� ���� �ϳ��� ����
	//�Լ�����: int fputc(int c ���Ͽ� ���� ����, FILE * pFile);
	//�����ϸ� �ش���� �����ϸ� eof(-1)
	//FILE* pFile =fopen("test.txt","w");
	//fputc('b',pFile);
	//fclose(pFile);
	
	//fgetc �Լ� ���Ͽ������� ���� �ϳ��ϳ� �б�
	//int fgetc(FILE* pFile);	
	//FILE* pFile = fopen("test.txt", "r");  read mode�� ���� ����
	//char c = fgetc(pFile); �ش� ���Ϸ� ���� �ѱ��� �о����.
	//fclose(pFile);    ���� �ݱ�

	while (feof(fp) == false) {
		int countWords = 1;
		char* words = strtok(fileTmp, " ");
		fgets(fileTmp, sizeof(fileTmp), fp);
		while (words != NULL) {
			if (countWords == 1) {
				strcpy(tmp.name, words);
				countWords++;
			}
			else if (countWords == 2) {
				tmp.id = (int)words;
				countWords++;
			}
			else {
				printf("words ������ �ٽ� Ȯ���غ�����.");
			}
			//�𸣰ٵ� �ФФ�
		}
		insertLast(L, tmp);
	
	}
	fclose(fp);

	printf("fileRead\n");
}

//insert
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


// int getLength() ����
int getLength(linkedList* L) {
	return L->length;
}

//ù ��° ���� ����
void insertFirst(linkedList* L, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
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
	L->length++;
}

//search
listNode* search(linkedList* L, element x) {
	listNode* temp = L->head;
	while (temp != NULL) {
		if (temp->data == x)
			return temp;
		else
			temp = temp->link;
	}
	return temp;
}

void reverse(linkedList* L) {
	listNode* currentNode, * previousNode, * nextNode;
	currentNode = L->head;
	previousNode = NULL;
	while (currentNode != NULL) {
		nextNode = currentNode->link;
		currentNode->link = previousNode;
		//���� �ڸ� �ٲ��ֱ�
		previousNode = currentNode;
		currentNode = nextNode;
	}
	L->head = previousNode;
}

//delete
int delete(linkedList* L, listNode* p) {
	listNode* pre;

	if (L->head == NULL)
		return false;
	if (p == NULL)
		return false;
	if (L->head == p) {
		L->head = p->link;
		free(p);
	}
	else {
		pre = L->head;
		while (pre->link != p) {
			pre = pre->link;
			if (pre == NULL)
				return false;
		}
		pre->link = p->link;
		free(p);
	}
	L->length--;
	return true;
}
//�� �� �ȵ� �ФФ�
void printList(linkedList* L) {
	listNode* print;
	print = L->head;
	while (print != NULL) {
		//printf(print->data.name);
		//printf(print->data.id);
		printf("\n");
		print = print->link;
	}
}

void play() {
	char tmp[300];
	linkedList* students = initList();
	char* rootFile = ".data/student.txt";
	fileRead(students, rootFile);

	gets_s(tmp, sizeof(tmp));
	char* command = strtok(tmp, " ");
	char* text = NULL;
	//printList �־�ߵǴµ� ������
	//search �ֱ�
	//insert �ֱ�
	//delete �ֱ�
	//reverse �ֱ�
	//getLength �ֱ�
	//�ٵ� ��� ����??
	if (strcmp(command, "print") == 0) {
		printList(students);
	}
	else if (strcmp(command, "delete") == 0) {
		int nbDeleteID = atoi(strtok_s(NULL, " ", &text));
		delete(students, nbDeleteID);
	}
	else if (strcmp(command, "reverse") == 0) {
		reverse(students);
	}

	else if (strcmp(command, "getLength") == 0) {
		getLength(students);
	}
}