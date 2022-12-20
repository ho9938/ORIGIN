#include <stdio.h>

int main()

{
	int start;
	int end;
	int term;
	printf("시작일을 입력하세요(일):");
	scanf("%d", &start);
	printf("종료일을 입력하세요(일):");
	scanf("%d", &end);
	term = end - start;
	printf("두 날짜의 차이는 %d일 입니다.", term);
}
