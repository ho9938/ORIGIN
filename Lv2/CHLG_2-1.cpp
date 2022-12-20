#include <stdio.h>
#define MAX_SIZE 20 // 스택의 크기 정의

char stack[MAX_SIZE];			 // 배열로 정의된 문자를 저장하는 스택 선언
int top = -1;					 // 스택의 내부 변수 top
int overflow = 0, underflow = 0; // 오버플로우, 언더플로우를 나타내는 상대 변수

int push(char x) // push(x) 함수
{
	if (top >= MAX_SIZE - 1) // 스택의 크기보다 크면
	{
		overflow = 1; // 오버플로우
	}
	else // 아니면
	{
		top++;			// top 포인터 1 증가
		stack[top] = x; // 그 위치에 자료 저장
	}
}

int pop() // pop() 함수
{
	if (top < 0) // 스택이 비어 있으면
	{
		underflow = 1; // 언더플로우
	}
	else // 아니면
	{
		while (top >= 0) // top포인터가 -1이 될때까지 반복
		{
			printf("%c", stack[top]); // 스택 출력 후
			top--;					  // top 포인터 1 감소
		}
	}
}

int main()
{								   // 메인 함수
	char A;						   //  문자 입력 변수
	while (scanf("%c", &A) != EOF) // 입력이 끝날 때까지 반복
	{
		push(A); // 스택에 push
	}
	pop(); // pop함수 사용(스택 출력, top포인터 1 감소 반복)
}
