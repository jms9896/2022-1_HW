#include <stdio.h>
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
	


}

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
