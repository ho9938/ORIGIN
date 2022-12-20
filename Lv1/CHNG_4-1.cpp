#include <stdio.h>

int main()

{
	int number;
	int m;
	int result;
	scanf("%d", &number);
	for(m=1; m<10; m++)
	{
		result=number*m;
		printf("%d*%d=%d\n", number, m, result);
	}
}
