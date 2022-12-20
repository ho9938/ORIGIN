#include <stdio.h>

int main()

{
	char name[11];
	float h;
	double w;
	printf("당신의 이름을 입력하세요: ");
	scanf("%s", name);
	printf("당신의 키를 입력하세요: ");
	scanf("%f", &h);
	printf("당신의 몸무게를 입력하세요: ");
	scanf("%lf", &w);
	printf("당신의 이름은 %s입니다.\n", name);
	printf("키는 %.2f이고, 몸무게는 %.1lf입니다.", h, w);
}
