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
	int month;
	int date;
	printf("연도와 월을 입력하세요 : ");
	scanf("%d", &year);
	scanf("%d", &month);
	if (month == 2)
	{
		if (isleap(year))
		{
			date = 29;
		}
		else
		{
			date = 28;
		}
	}
	else if (month == 4 or month == 6 or month == 9 or month == 11)
	{
		date = 30;
	}
	else
	{
		date = 31;
	}
	printf("%d년 %d월의 마지막날은 %d입니다. \n", year, month, date);
}
