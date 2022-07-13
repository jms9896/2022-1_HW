#include <stdio.h>
#include <stdbool.h>

#define MAX(a,b) a > b ? a : b 
// ��ũ���Լ� & ���׿�����. 
// MAX(a,b)�� �����ϴµ�(��ũ���Լ�), 
// a�� b���� ũ�ٸ�(T) a����, �ƴ϶��(f) b����(���׿�����)
#define MAX_DEGREE 50 

typedef struct {			// ����ü polynomial ���� 
	int degree;		// ���׽��� ������ ������ ���� 
	float coef[MAX_DEGREE];	// ���׽��� �� ���� ����� ������ 1���� �迭 
}polynomial;

polynomial addPoly(polynomial A, polynomial B) {
	// Fill your code
	polynomial C;
	int indexA = 0, indexB = 0, indexC = 0;
	int degreeA = A.degree, degreeB = B.degree;
	C.degree = MAX(degreeA, degreeB);
	//while (isZero(A) != false && isZero(B) != false) {
	//	if (maxExp(A) < maxExp(B)) {
	//	}
	//}

	while (indexA <= A.degree && indexB <= B.degree) {
		// A�� B�� ������ �۰ų� ������ ��� �ݺ� 
		if (degreeA < degreeB) {
			C.coef[indexC++] = B.coef[indexB++];
			//����� ����ֱ�
			degreeB--;
		}
		else if (degreeA == degreeB) {
			C.coef[indexC++] = A.coef[indexA++] + B.coef[indexB++];
			//����� �Ȱ��� ��, �������
			degreeA--;
			degreeB--;
		}

		else {
			// degreeA>degreeB
			C.coef[indexC++] = A.coef[indexA++];
			degreeA--;
		}
	}

	return C;
}


//
//
//void zeroP(polynomial* A) {
//	A->degree = 0; // ������ 0�̸� �ʱ�ȭ
//	for (int i = 0; i < MAX_DEGREE; i++) {
//		A->coef[i] = 0; // ��� �˴� 0���� �ʱ�ȭ
//	}
//}
//
//bool iszero(polynomial* C) {
//	// ���׽��� 0���� �ƴ��� �Ǻ�
//	for (int i = 0; i < MAX_DEGREE; i++) {
//		if (C->degree != NULL && C->degree != 0) {
//			// 0�̳� NULL�� �ƴϸ� false ��ȯ
//			return false;
//			break;
//		}
//		
//	}
//}


void printPoly(polynomial P) {
	int i, degree = P.degree;
	
	for(i=0; i<=P.degree; i++) {
		printf("%3.0fx^%d", P.coef[i], degree--);
		if(i < P.degree) printf(" +");
	}
	printf("\n");
}

int main() {
	polynomial A = {3, {4, 3, 5, 0}};
	polynomial B = {4, {3, 1, 0, 2, 1}};
	
	polynomial C = addPoly(A, B);
	
	printf("\n A(x)="); printPoly(A);
	printf("\n B(x)="); printPoly(B);
	printf("\n C(x)="); printPoly(C);
	
	return 0;
}
