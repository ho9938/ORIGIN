#include <stdio.h>

int main()

{
	int starthour;
	int startminute;
	int startsecond;
	int starttime;
	int D;
	int arrivehour;
	int arriveminute;
	int arrivesecond;
	int arrivetime;
	printf("버스의 출발 시간을 시, 분, 초로 나누어 정수로 입력하세요: ");
	scanf("%d", &starthour);
	scanf("%d", &startminute);
	scanf("%d", &startsecond);
	printf("버스의 운행 시간을 초 단위로 입력하세요: ");
	scanf("%d", &D);
	starttime = starthour*3600 + startminute*60 + startsecond;
	arrivetime = starttime + D;
	arrivehour = (arrivetime/3600)%24;
	arriveminute = (arrivetime%3600)/60;
	arrivesecond = arrivetime%60;
	printf("버스의 도착 시간은 %d시 %d분 %d초입니다.", arrivehour, arriveminute, arrivesecond);
}
