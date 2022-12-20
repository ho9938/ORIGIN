#include <stdio.h>

int main()

{
	int l;
	int h;
	float result;
	printf("******* 삼각형 넓이 구하기 ********\n");
	printf("밑변의 길이와 높이를 띄워서 입력하세요:");
	scanf("%d ", &l);
	scanf("%d", &h);
	result = l * h / 2.0;
	printf("입력된 삼각형의 넓이는 %.1f입니다.", result);
}
