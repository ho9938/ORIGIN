#include <stdio.h>
#define MAX_SIZE 100 // 스택의 최대 크기

int stack[MAX_SIZE], top = -1;	  // 스택 배열 변수 선언, top=-1
int decimal[MAX_SIZE], topD = -1; // 스택(decimal) 배열 변수 선언, topD=-1

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
		top--;				  // top 포인터 1감소
		return tmp;			  // tmp 값을 반환
	}
}

int pushD(int x) // pushD(x) 연산 : 십의 자리보다 큰 수를 받아들이기 위한 보조 함수
{
	if (topD >= MAX_SIZE - 1)	   // 스택 오버플로우 조건
		printf("스택 오버플로우"); // 오버플로우이면 에러 출력
	else
	{					   // 아니면
		topD++;			   // topD포인터 1증가
		decimal[topD] = x; // 스택에 저장
	}
}

int popD() // popD() 연산 : 십의 자리보다 큰 수를 받아들이기 위한 보조 함수
{
	if (topD < 0)
	{							   // 스택 언더플로우 조건
		printf("스택 언더플로우"); // 언더플로우이면 에러 출력
		return -1;				   // 에러 코드를 반환
	}
	else
	{							 // 아니면
		int tmp = decimal[topD]; // 변환할 내용을 tmp에 저장
		topD--;					 // topD 포인터 1감소
		return tmp;				 // tmp 값을 반환
	}
}

int num(char x) // num(x) 함수 : x가 피연산자인지 확인함.
{
	if (x == '0' || x == '1' || x == '2' || x == '3' || x == '4' || x == '5' || x == '6' || x == '7' || x == '8' || x == '9') // x가 0~9이면
		return 1;																											  // 피연산자
	else																													  // 아니면
		return 0;																											  // 연산자
}

int NUM(char x) // NUM(X) 함수 : 문자인 char x를 숫자인 int x로 바꿈.
{
	int tmp; // 임시 저장 변수
	if (x == '0')
		tmp = 0; // char x=0이면 tmp에 0값을 저장
	else if (x == '1')
		tmp = 1; // char x=1이면 tmp에 1값을 저장
	else if (x == '2')
		tmp = 2; // char x=2이면 tmp에 2값을 저장
	else if (x == '3')
		tmp = 3; // char x=3이면 tmp에 3값을 저장
	else if (x == '4')
		tmp = 4; // char x=4이면 tmp에 4값을 저장
	else if (x == '5')
		tmp = 5; // char x=5이면 tmp에 5값을 저장
	else if (x == '6')
		tmp = 6; // char x=6이면 tmp에 6값을 저장
	else if (x == '7')
		tmp = 7; // char x=7이면 tmp에 7값을 저장
	else if (x == '8')
		tmp = 8; // char x=8이면 tmp에 8값을 저장
	else if (x == '9')
		tmp = 9; // char x=9이면 tmp에 9값을 저장
	return tmp;
}

int main() // main() 함수
{
	char x;				  // 문자 일벽 변수 x
	int B = 1, price = 0; // 십의 자리보다 큰 수를 받아들이기 위한 보조 변수
	while (1)
	{					 // 반복
		scanf("%c", &x); // x를 입력받음
		if (x == '\n')	 // 줄 바꿈이 입력되면
			break;		 // 반복문 종료
		else
		{					   // 아니면
			if (num(x))		   // x가 피연산자이면
				pushD(NUM(x)); // 스택(decimal)에 저장
			else if (x == '+' || x == '-' || x == '*' || x == '/')
			{					   // x가 연산자이면
				int b = pop();	   // 스택 출력 후 그 값을 b에 저장
				int a = pop();	   // 스택 출력 후 그 값을 a에 저장
				if (x == '+')	   // x가 +이면
					push(a + b);   // a+b값을 스택에 저장
				else if (x == '-') // x가 -이면
					push(a - b);   // a-b값을 스택에 저장
				else if (x == '*') // x가 *이면
					push(a * b);   // a*b값을 스택에 저장
				else if (x == '/') // x가 /이면
					push(a / b);   // a/b값을 스택에 저장
				topD = 10;		   // topD포인터를 10으로 설정 : 스택(decimal)에 입력되는 반복문을 회피하기 위함
			}
			else if (x == ' ')
			{ // x가 공백이면
				if (topD < 10)
				{ // topD값이 10보다 작으면
					while (topD != -1)
					{						// topD값이 -1이 아닐 동안
						int DP = popD();	// 보조 변수 DP에 스택(Decimal) 값 저장
						DP = DP * B;		// DP값에 B값을 곱함
						price = price + DP; // price값에 DP값을 더함
						B = B * 10;			// B값에 10을 곱함
					}
					push(price); // price값을 스택에 저장
				}
				topD = -1; // topD값을 -1로 초기화
				B = 1;	   // B값을 1로 초기화
				price = 0; // price값을 0으로 초기화
			}
		}
	}
	printf("%d", pop()); // 스택에 남아있는 값을 출력함
}
