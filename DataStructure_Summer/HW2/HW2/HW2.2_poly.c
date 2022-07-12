#include <stdio.h>
#include <stdbool.h>

#define MAX(a,b) a > b ? a : b 
// 매크로함수 & 삼항연산자. 
// MAX(a,b)를 정의하는데(매크로함수), 
// a가 b보다 크다면(T) a선택, 아니라면(f) b선택(삼항연산자)
#define MAX_DEGREE 50 

typedef struct {			// 구조체 polynomial 정의 
	int degree;		// 다항식의 차수를 저장할 변수 
	float coef[MAX_DEGREE];	// 다항식의 각 항의 계수를 저장할 1차원 배열 
}polynomial;

polynomial addPoly(polynomial A, polynomial B) {
	// Fill your code
	polynomial* C;
	// C=zeroP()
	while (isZero(A) != false && isZero(B) != false) {
		if (maxExp(A) < maxExp(B)) {
		}
	}
}




void zeroP(polynomial* A) {
	A->degree = 0; // 차수가 0이면 초기화
	for (int i = 0; i < MAX_DEGREE; i++) {
		A->coef[i] = 0; // 계수 죄다 0으로 초기화
	}
}

bool iszero(polynomial* C) {
	// 다항식이 0인지 아닌지 판별
	for (int i = 0; i < MAX_DEGREE; i++) {
		if (C->degree != NULL && C->degree != 0) {
			// 0이나 NULL이 아니면 false 반환
			return false;
			break;
		}
		
	}
}

int maxExp(polynomial A) {

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
