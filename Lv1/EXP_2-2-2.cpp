#include <stdio.h>

int isleap(int endyear)
{
	if (endyear % 4 == 0 && endyear % 100 != 0 || endyear % 400 == 0)
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
	int startyear, startmonth, startdate;
	int endyear, endmonth, enddate;
	int term = 0;
	printf("시작일을 입력하세요(년 월 일):");
	scanf("%d", &startyear);
	scanf("%d", &startmonth);
	scanf("%d", &startdate);
	printf("종료일을 입력하세요(년 월 일):");
	scanf("%d", &endyear);
	scanf("%d", &endmonth);
	scanf("%d", &enddate);
	term = term + enddate;
	while (startmonth != endmonth)
	{
		endmonth--;
		if (endmonth == 4 or endmonth == 6 or endmonth == 9 or endmonth == 11)
		{
			term = term + 30;
		}
		else if (endmonth == 2)
		{
			if (isleap(endyear))
			{
				term = term + 29;
			}
			else
			{
				term = term + 28;
			}
		}
		else
		{
			term = term + 31;
		}
	}
	term = term - startdate;
	printf("두 날짜의 차이는 %d일 입니다. \n", term);
