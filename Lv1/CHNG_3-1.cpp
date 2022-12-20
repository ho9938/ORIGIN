#include <stdio.h>

int main()

{
	int n;
	int factorial;
	scanf("%d", &n);
	printf("%d!", n);
	for(factorial=1; n>0; n--)
	{
		factorial=factorial*n;
	}
	printf("=%d", factorial);
}
