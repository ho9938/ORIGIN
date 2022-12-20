#include <stdio.h>

int main()

{
	int like;
	int hate;
	printf("당신이 좋아하는 숫자는? ");
	scanf("%d", &like);
	printf("당신이 싫어하는 숫자는? ");
	scanf("%d", &hate);
	printf("당신이 좋아하는 숫자는 %d입니다.\n", like);
	printf("당신이 싫어하는 숫자는 %d입니다.\n", hate);
}
