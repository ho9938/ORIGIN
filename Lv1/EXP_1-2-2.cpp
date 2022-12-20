#include <stdio.h>

int main()

{
	int time;
	int hour;
	int minute;
	int second;
	printf("******** 시/분/초 변환 프로그램 *******\n");
	printf("초를 입력하세요:");
	scanf("%d", &time);
	hour = time / 3600;
	minute = (time % 3600) / 60;
	second = (time % 3600) % 60;
	printf("%d시 %d분 %d초입니다.", hour, minute, second);
}
