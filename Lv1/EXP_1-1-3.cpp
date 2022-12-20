#include <stdio.h>

int main()

{
	char name[11];
	char birthday[20];
	char group[10];
	printf("회원의 이름을 입력하세요:");
	scanf("%s", name);
	printf("회원의 생년월일을 형식에 맞춰 입력하세요<형식:2001-02-17>:");
	scanf("%s", birthday);
	printf("보내는 회사명을 입력하세요:");
	scanf("%s", group);
	printf("%s 회원님께\n", name);
	printf("회원님의 생일을 진심으로 축하드립니다!\n");
	printf("%s \t", birthday);
	printf("From. %s", group);
}
