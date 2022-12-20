#include <stdio.h>

int isleap(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int year;
	printf("xxx 윤년 판별 프로그램 xxx\n");
	printf("연도를 입력하세요: ");
	scanf("%d", &year);
	if (isleap(year))
	{
		printf("윤년");
	}
	else
	{
		printf("평년");
	}
}
