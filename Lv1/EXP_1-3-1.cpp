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
	printf("������ ��� �ð��� ��, ��, �ʷ� ������ ������ �Է��ϼ���: ");
	scanf("%d", &starthour);
	scanf("%d", &startminute);
	scanf("%d", &startsecond);
	printf("������ ���� �ð��� �� ������ �Է��ϼ���: ");
	scanf("%d", &D);
	starttime = starthour*3600 + startminute*60 + startsecond;
	arrivetime = starttime + D;
	arrivehour = (arrivetime/3600)%24;
	arriveminute = (arrivetime%3600)/60;
	arrivesecond = arrivetime%60;
	printf("������ ���� �ð��� %d�� %d�� %d���Դϴ�.", arrivehour, arriveminute, arrivesecond);
}
