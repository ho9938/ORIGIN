#include <stdio.h>
#include <stack>	 // 헤더파일
using namespace std; // std 공간 사용 선언

stack<int> S; // S는 스택의 변수명

int main()
{
	int i, n;				// 반복 변수 i, 결과 입력 변수 n
	for (i = 0; i < 5; i++) // 5번 반복
	{
		scanf("%d", &n); // n을 입력받음
		S.push(n);		 // 스택에 등록
	}
	for (i = 0; i < 5; i++) // 5번 반복
	{
		printf("%d ", S.top()); // 스택 제일 위의 요소 출력
		S.pop();				// 스택 제일 위의 요소 제거
	}
	return 0;
}
