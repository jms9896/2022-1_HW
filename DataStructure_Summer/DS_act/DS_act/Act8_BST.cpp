#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int BTData;
typedef struct BinaryTreeNode {
	BTData key;
	struct BinaryTreeNode* left, * right;
}BinTree;

BinTree* root = NULL;
BinTree* parent = root;

BinTree* createBT(int num) {
	BinTree* root = (BinTree*)malloc(sizeof(BinTree));
	root->key = num;
	root->left = NULL;
	root->right = NULL;
	return root;
}

BinTree* searchBST(BinTree* bt, BTData x) {
	BinTree* p = bt;
	while (p != NULL) {
		if (x == p->key)
			return p;
		if (x < p->key)
			p = p->left;
		else
			p = p->right;
	}
	printf("ERROR : 찾는 키가 없습니다\n");
	return NULL;
}

void insertBST(BinTree* bt, BTData x) 
{
	//여기 채워야됨. malloc
	BinTree* p = bt;
	BinTree* parent = NULL;
	BinTree* newNode;
	while (p != NULL) {
		if (x == p->key)
			return;
		if (x < p->key)
			p = p->left;
		else
			p = p->right;
	}
	newNode->key = x;
	newNode->left = NULL;
	newNode->right = NULL;

	if (bt == NULL)
		bt = newNode;
	else if (x < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;
}

void deleteBST(BinTree* bt, BTData x)
{
	BinTree* p = NULL, * q = NULL;
	BinTree* parent = NULL;

	if (p == NULL) return;
	if (p->left == NULL && p->right == NULL) {
		if (parent->left == p) {
			parent->left = NULL;
		}
		else {
			parent->right = NULL;
		}
	}
	else if (p->left == NULL || p->right == NULL) {
		if (p->left != NULL) {
			if (parent->left == p) {
				parent->left = p->left;
			}
			else parent->right = p->left;
		}
		else {
			if (parent->left == p) {
				parent->left = p->right;
			}
			else {
				parent->right = p->right;
			}
		}
	}
	else if (p->left != NULL && p->right != NULL) {
		q = p->left;
		while (q->right != NULL) {
			q = q->right;
		}
		
		p->key = q->key;
		deleteBST(p->left, q->key);
	}

}


int main(void)
{
	BinTree* root;
	insertBST(root, 5);
	insertBST(root, 3);	
	insertBST(root, 7);
	insertBST(root, 2);

}