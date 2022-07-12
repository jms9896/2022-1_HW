#include <stdio.h>

typedef struct {
	int row;
	int col;
	int value;
}matrix;

void transposeSM(matrix a[], matrix b[]) {
	// Fill your code
	int m, n, v, i, j, p;
	m = a[0].row;
	n = a[0].col;
	v = a[0].value;
	b[0].row = n;
	b[0].col = m;
	b[0].value = v;
	
	if(v > 0) {		// 0이 아닌 원소가 있는 경우에만 전치 연산 수행 
	

	코드를 채워주세요	


	}
}

int main() {
	int i, j;
	matrix a[11] = {	{8,7,10}, 
						{0,2,2},
						{0,6,12},
						{1,4,7},
						{2,0,23},
						{3,3,31},
						{4,1,14},
						{4,5,25},
						{5,6,6},
						{6,0,52},
						{7,4,11}
	};
	matrix b[11] = {0, };
	transposeSM(a, b);
	
	printf("Matrix a\n");
	for(i=0; i<11; i++)
		printf("%d: %d %d %d\n", i, a[i].row, a[i].col, a[i].value);
	printf("Transpose Matrix b\n");
	for(i=0; i<11; i++)
		printf("%d: %d %d %d\n", i, b[i].row, b[i].col, b[i].value);
	return 0;
}
