#include <stdio.h>

typedef struct {
	int row;
	int col;
	int value;
}matrix;

void transposeSM(matrix a[], matrix b[]) {
	// Fill you code
	int m, n, v, i, j, p;
	m = a[0].row; // 행
	n = a[0].col; // 열
	v = a[0].value; // 값. 0이 아닌 원소수
	b[0].row = n;
	b[0].col = m;
	b[0].value = v;
	// b에 전치 할 값 삽입
	if (v > 0) {		
		p = 1;
		for (i = 0; i < n; i++)	// 열 별 전치		
			for (j = 1; j <= v; j++) // 0이 아닌 원소에 대해서 반복	
				if (a[j].col == i) {  // 원소가 있으면 삽입	
					b[p].row = a[j].col; // 행 열 전치
					b[p].col = a[j].row;
					b[p].value = a[j].value;
					p++;
				}
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
