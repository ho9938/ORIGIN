#include <stdio.h>

int main()

{
	int num;
	int a=0;
	char A[100];
	scanf("%d", &num);
	while(num>0)
		{
		A[a]=num%2;
		a++;
		num=num/2;
	}
	while(a>0)
	{
		a--;
		printf("%d", A[a]);
	}
}
