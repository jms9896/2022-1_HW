#include <stdio.h>
#define MAX(a,b) a > b ? a : b
#define MAX_DEGREE 50

typedef struct {			// 구조체 polynomial 정의 
	int degree;		// 다항식의 차수를 저장할 변수 
	float coef[MAX_DEGREE];	// 다항식의 각 항의 계수를 저장할 1차원 배열 
}polynomial;

polynomial addPoly(polynomial A, polynomial B) {
	// Fill your code
	polynomial C;	// 다항식 덧셈의 결과 다항식을 저장할 polynomial 구조체 변수 선언 
	int indexA = 0, indexB = 0, indexC = 0;
	int degreeA = A.degree, degreeB = B.degree;	
    C.degree = MAX(degreeA, degreeB);

	while(degreeA <= A.degree && degreeB <= B.degree){
	    if(degreeA < degreeB) {
	        C.coef[indexC++] = B.coef[indexB++];
	        degreeB--;
	    else if(degreeA == degreeB) {     
            C.coef[indexC++] = A.coef[indexA++] + B.coef[indexB++];
            degreeA--;
			degreeB--;
            
        //else if(degreeA > degreeB)
        else {
	        C.coef[indexC++] = A.coef[indexA++];
			degreeA--;
        }
	}
	
	return C;
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
