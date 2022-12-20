#include <stdio.h>

int main()

{
	int a;
	int b;
	int sum;
	scanf("%d", &a);
	scanf("%d", &b);
	for(sum=0; a>b; a--)
	{
		printf("%d+", a);
		sum=sum+a;
	}
	for(sum=0; a<b; a++)
	{
		printf("%d+", a);
		sum=sum+a;
	}
	sum=sum+b;
	printf("%d", b);
	printf("=%d", sum);
}
