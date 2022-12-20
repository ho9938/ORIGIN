#include <stdio.h>

int main()

{
	float F;
	double C;
	printf("- 섭씨 온도를 화씨 온도로 변환하는 프로그램 -\n");
	printf("섭씨 온도를 입력하세요: ");
	scanf("%lf", &C);
	F = C * 9 / 5 + 32;
	printf("%.3f", F);
}
