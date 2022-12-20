#include <stdio.h>
#define MAX_SIZE 100 // 스택의 최대 크기

int stack[MAX_SIZE], top = -1; // 스택 배열 변수 선언, top=-1

int isfull() // isfull 함수
{
	if (top >= MAX_SIZE - 1) // top포인터가 최대 크기 -1이상이면
		return 1;			 // 오버플로우
	else					 // 아니면
		return 0;			 // 오버플로우 아님
}

int isempty() // isempty 함수
{
	if (top < 0)  // top포인터가 0보다 작으면
		return 1; // 언더플로우
	else		  // 아니면
		return 0; // 언더플로우 아님
}

int push(int x) // push(x) 연산
{
	if (isfull())				   // 스택 오버플로우 조건
		printf("스택 오버플로우"); // 오버플로우이면 에러 출력
	else
	{					// 아니면
		top++;			// top포인터 1증가
		stack[top] = x; // 스택에 저장
	}
}

int pop() // pop() 연산
{
	if (isempty())
	{							   // 스택 언더플로우 조건
		printf("스택 언더플로우"); // 언더플로우이면 에러 출력
		return -1;				   // 에러 코드를 반환
	}
	else
	{						  // 아니면
		int tmp = stack[top]; // 반환할 내용을 tmp에 저장
		top--;				  // tmp 포인터 1감소
		return tmp;			  // tmp 값을 반환
	}
}

int F(int x) // F(x) 연산 : 입력 문자와 스택에 저장된 우선순위에 따라 연산/출력함
{
	if (x == '(') // x가 '('이면
		push(x);  // 스택에 저장
	else if (x == '+' || x == '-')
	{																							 // x가 '+'나 '-'이면
		while (stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/') // stack[top]값이 '+'or'-'or'*'or'/'일 동안
			printf(" %c", pop());																 // 스택 출력(앞에 공백 추가)
		push(x);																				 // x를 스택에 저장
	}
	else if (x == '*' || x == '/')
	{												   // x가 '*'나 '/'이면
		while (stack[top] == '*' || stack[top] == '/') // stack[top]값이 '*'or'/'일 동안
			printf(" %c", pop());					   // 스택 출력(앞에 공백 추가)
		push(x);									   // x를 스택에 저장
	}
}

int main() // main() 함수
{
	char x; // 문자 입력 변수 x
	int A;	// 피연산자의 자릿수를 확인하기 위한 변수
	while (1)
	{					 // 반복
		scanf("%c", &x); // x를 입력받음
		if (x == '\n')	 // 줄 바꿈이 입력되면
			break;		 // 반복문 종료
		else
		{ // 아니면
			if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(')
			{		   // 연산자가 입력되면
				F(x);  // F(x) 연산
				A = 1; // A포인터를 1로 설정
			}
			else if (x == ')')
			{							  // 닫는 괄호가 입력되면
				while (stack[top] != '(') // stack[top] 값이 '('이 되지 않을 동안
					printf(" %c", pop()); // 스택 출력
				pop();					  // 스택에서 pop()
				A = 1;					  // A포인터를 1로 설정
			}
			else
			{ // 아니면
				if (A == 1)
				{					  // A포인터가 1이면(x값이 십의 자리 숫자이면)
					printf(" %c", x); // x값 출력(앞에 공백 추가)
					A = 0;			  // A포인터를 0으로 초기화
				}
				else				 // 아니면
					printf("%c", x); // x값 출력
			}
		}
	}
	while (isempty() == 0)
	{						  // 스택이 비기 전까지
		printf(" %c", pop()); // 스택 값 출력
	}
}
