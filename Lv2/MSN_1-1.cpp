#include <stdio.h>
#define MAX_SIZE 100 // 스택의 크기 정의

int stack[MAX_SIZE], top = -1;

int isfull() // isfull 함수
{
	if (top < MAX_SIZE) // 스택의 크기보다 작으면
		return 1;		// 1 반환
	else				// 아니면
		return 0;		// 0 반환
}

int isempty() // isempty 함수
{
	if (top < 0)  // 스택이 비어 있으면
		return 1; // 1 반환
	else		  // 아니면
		return 0; // 0 반환
}

int push(int x) // push(x) 함수
{
	if (isfull())		  // 스택이 꽉 차 있지 않으면
		stack[++top] = x; // top 포인터 1 증가, 그 위치에 자료 저장
}

int pop() // pop() 함수
{
	if (isempty()) // 스택이 비어 있으면
		return -1; // -1 반환
	else
	{							// 아니면
		int tmp = stack[top--]; // top 포인터 1 감소,
		return tmp;				// stack값 반환
	}
}

int main() // main() 함수
{
	int i, n;				// 반복 변수 i, 결과 입력 변수 n
	for (i = 0; i < 5; i++) // 5번 반복
	{
		scanf("%d", &n); // n을 입력받음
		push(n);		 // 스택에 저장
	}
	for (i = 0; i < 5; i++)
	{						  // 5번 반복
		printf("%d ", pop()); // 스택에서 추출한 값 출력
	}
	return 0;
}
