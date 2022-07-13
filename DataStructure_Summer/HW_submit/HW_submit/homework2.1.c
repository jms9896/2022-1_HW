//2015251165 정민성
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100		// 배열의 최대 크기

typedef int element;
typedef struct {
	element list[MAX_SIZE];	// 배열 정의
	int length;		// 현재 배열에 저장된 자료들의 개수
}ArrayListType;

// 오류 처리 함수nnnn
void error(char *message)
{
	printf("%s\n", message);
}

// 리스트 초기화
void init(ArrayListType *L)
{
	L->length = 0;
}

// 빈 리스트 검사
// 리스트가 비어 있으면 1을 반환
// 그렇지 않으면 0을 반환
int isEmpty(ArrayListType *L)
{
	return L->length == 0;
}

// 리스트가 포화상태인 검사
// 리스트가 가득차 있으면 1을 반환
// 그렇지 않으면 0을 반환
int isFull(ArrayListType *L)
{
	return L->length == MAX_SIZE;
}

// 리스트의 모든 요소 출력
void display(ArrayListType *L)
{
	int i;
	printf("===Print Lists===\n");
	for (i=0; i<L->length; i++)
		printf("ArrayList[%d]: %d\n", i, L->list[i]);
}

// 삽입 함수 
// pos: 삽입하고자 하는 위치
// item: 삽입하고자 하는 자료
void insert(ArrayListType *L, int pos, element item)
{
	// Fill your code
	if (isFull(L)) { 
		// 리스트 가득 차면 오류
		error("List is Full!");

	}
	else if ((pos < 0) || (pos > L->length)) {
		// 넣으려는 위치가 0보다 작거나, 리스트 맨 끝값보다 크면 에러
		error("Index Error");
	}
	else {
		for (int i = (L->length - 1); i >= pos; i--) {
			// 맨 끝 넣는게 아니기 때문에 length-1부터 시작
			L->list[i + 1] = L->list[i];
			// 리스트를 뒤에서부터 한 칸씩 밀어서 넣기
		}
		L->list[pos] = item;
		// 리스트 삽입 위치 데이터 노드에 값을 삽입
		L->length++;
		// 리스트 크기를 1 증가시켜줌.
		// 버퍼크기는 고정이나, 리스트 맨 마지막 크기를 알 수 있는 방법임.
		printf("ArrayList[%d]에 %d 삽입\n", pos, item);
		//리스트 삽입 메시지 출력
	}
	
	// 완료

}

// 리스트 맨 앞에 요소 삽입
void insertFirst(ArrayListType *L, element item)
{
	// Fill your code
	if (isFull(L)) { // 리스트 꽉 차있으면 에러 출력
		error("List is Full!");

	}

	else {
		for (int i = (L->length - 1); i >= 0; i--) {
			//리스트를 뒤에서부터 1씩 줄여주는데, 이유는 후술
			L->list[i + 1] = L->list[i];
			//리스트 맨 뒤에부터 한 칸씩 뒤로 밀어주기
		}
		L->list[0] = item;
		//남는 0번째(첫번째)에 데이터 삽입
		L->length++;
		//리스트 크기를 늘려줘야 맨 마지막값과 리스트의 정확한 크기를 알 수 있음
		printf("ArrayList[%d]에 %d 삽입\n", 0, item);
		//리스트 삽입 메시지 출력
	}
	// 완료

}

// 리스트 맨 끝에 요소 삽입
void insertLast(ArrayListType *L, element item)
{
	// Fill your code
	if (isFull(L)) { //리스트 꽉 차면 못 넣으니까
		error("List is Full!");

	}

	else {
		L->list[L->length] = item;
		// length가 리스트 제일 마지막이므로, 해당 위치에 값 삽입
		L->length++;
		printf("ArrayList[%d]에 %d 삽입\n", L->length, item);
	}
	//완료
}

// 삭제 함수
// pos: 삭제하고자 하는 위치
// 반환값: 삭제되는 자료
element delete_(ArrayListType *L, int pos)
{
	// Fill your code
	element item;
	if (isEmpty(L)) { //지워야하는데 빈리스트면 못지우니까 에러
		error("List is Empty!");
	}
	else if ((pos < 0) || (pos >= L->length)) {
		//삭제 위치 이상하면 에러
		error("Index Error");
	}
	else {
		item = L->list[pos];
		//일단 지우려는 위치의 값을 기억하고
		for (int i = pos; i < L->length - 1; i++) {
			/*지우려는 위치(pos)에서 길이에 - 1까지 i값 증가.
			왜냐하면 length는 마지막데이터인데, 
			이걸 앞으로 빼야하기때문에 이따가 i+1을 해줄 것임.
			i+1하면 length라서 length-1 하는것*/
			L->list[i] = L->list[i + 1];
		}
		L->length--;
		printf("ArrayList[%d]의 %d 삭제\n", pos, item);
		return item;
	}
	// 완료
}

// 리스트의 모든 요소 삭제
void clear(ArrayListType *L)
{
	// Fill your code
	for (int i = 0; i <= L->length; i++) {
		L->list[0] = NULL;
		// 그냥 리스트 길이만 0으로 해주면 최초주솟값 끊어주니까 clear
	}
	printf("ArrayList Clear\n");
	//완료
	
}

// pos 위치의 요소를 item으로 교체
void replace(ArrayListType *L, int pos, element item)
{
	// Fill your code
	L->list[pos] = item;
	// 해당 위치 노드 데이터값만 바꿔주기
	printf("ArrayList[%d]의 %d 교체\n", pos, item);

	//완료
}


int main()
{
	ArrayListType* plist;

	// ListType를 동적으로 생성하고 ListType를 가리키는 
	// 포인터를 함수의 파라미터로 전달한다.
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
