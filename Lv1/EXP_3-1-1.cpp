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
} // 윤년 체크 함수
int MONTH(int month)
{
	if (month == 4 or month == 6 or month == 9 or month == 11)
	{
		return 1;
	}
	else
	{
		return 0;
	}
} // 4,6,9,11월(30일인 달)을 체크하는 함수

int main()
{
	int startyear, startmonth, startdate;
	int endyear, endmonth, enddate;
	int term = 0;
	scanf("%d", &startyear);
	scanf("%d", &startmonth);
	scanf("%d", &startdate);
	scanf("%d", &endyear);
	scanf("%d", &endmonth);
	scanf("%d", &enddate);
	if (endyear > startyear || endyear == startyear && endmonth > startmonth || endyear == startyear && endmonth == startmonth && enddate > startdate) /*
																																						*/
																																					   // 기준 날짜가 D-day 날짜보다 빠른 경우
	{
		term = term + enddate;
		while (endmonth != 1)
		{
			endmonth--;
			if (MONTH(endmonth))
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
		while (startyear != endyear)
		{
			endyear--;
			if (isleap(endyear))
			{
				term = term + 366;
			}
			else
			{
				term = term + 365;
			}
		}
		while (startmonth != 1)
		{
			startmonth--;
			if (MONTH(startmonth))
			{
				term = term - 30;
			}
			else if (startmonth == 2)
			{
				if (isleap(startyear))
				{
					term = term - 29;
				}
				else
				{
					term = term - 28;
				}
			}
			else
			{
				term = term - 31;
			}
		}
		term = term - startdate;
		printf("D-%d", term);
	}
	else if (endyear == startyear && endmonth == startmonth && enddate == startdate) // 기준 날짜가 D-day 날짜와 같은 경우
	{
		printf("D-day");
	}
	else // 기준 날짜가 D-day 날짜보다 느린 경우
	{
		term = term + startdate;
		while (startmonth != 1)
		{
			startmonth--;
			if (MONTH(startmonth))
			{
				term = term + 30;
			}
			else if (startmonth == 2)
			{
				if (isleap(startyear))
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
		while (endyear != startyear)
		{
			startyear--;
			if (isleap(startyear))
			{
				term = term + 366;
			}
			else
			{
				term = term + 365;
			}
		}
		while (endmonth != 1)
		{
			endmonth--;
			if (MONTH(endmonth))
			{
				term = term - 30;
			}
			else if (endmonth == 2)
			{
				if (isleap(endyear))
				{
					term = term - 29;
				}
				else
				{
					term = term - 28;
				}
			}
			else
			{
				term = term - 31;
			}
		}
		term = term - enddate;
		printf("D+%d", term);
	}
}
