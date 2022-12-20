#include <stdio.h>

int swap(int *a, int *b) // 두 변수의 값을 교환하는 함수
{
	int t = *a;
	*a = *b;
	*b = t;
}

int main()

{
	int i, j;
	int everage = 0;
	int data[4];

	for (i = 0; i <= 4; i++) // 입력된 값을 스캔하여 배열에 저장함.
		scanf("%d", &data[i]);

	for (i = 0; i <= 4; i++) // 거품정렬
		for (j = i + 1; j <= 4; j++)
			if (data[i] > data[j])
				swap(&data[i], &data[j]);

	for (i = 0; i <= 4; i++) // 총합을 구함.
	{
		everage = everage + data[i];
	}
	everage = everage / 5; // 총합을 5로 나누어 평균을 구함.

	printf("%d\n", everage); // 평균을 출력함.
	printf("%d", data[2]);	 // 중앙값을 출력함.
}
