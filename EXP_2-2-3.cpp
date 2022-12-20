#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

int W, H, LV;			  // 가로 크기, 세로 크기, 난이도
int cnt, allCnt, allMine; // 뒤집은 칸의 개수, 뒤집어야 할 모든 칸의 수, 지뢰의 전체 개수
int map[111][111];		  // 맵 저장 배열
int info[111][111];		  // 지뢰 주변 정보를 저장한 배열
int visit[111][111];	  // (x,y)를 뒤집었는지 확인하는 배열
int num[100];			  // 가로, 세로, 레벨 값을 입력받기 위한 배열
int tenms, sec, min;	  // 1/100초, 1초, 1분
int leftMine;			  // 남은 지뢰의 개수

int makeMap() // 맵 생성 함수
{
	srand(time(NULL)); // 난수표 초기화

	if (LV == 1)
		allMine = W * H / 10; // 난이도에 따른 지뢰 개수 설정
	else if (LV == 2)
		allMine = W * H / 8;
	else
		allMine = W * H / 5;

	allCnt = W * H - allMine; // 뒤집어야 할 모든 칸의 수 설정
	leftMine = allMine;		  // 남은 지로의 개수를 모든 개수로 설정

	for (int i = 1; i <= allMine; i++)
	{							 // 랜덤 지뢰 생성
		int t1 = rand() % W + 1; // 임의의 x좌표 생성
		int t2 = rand() % H + 1; // 임의의 y좌표 생성
		if (map[t1][t2] == 0)	 // (x,y)가 지뢰로 선정되지 않았으면
			map[t1][t2] = 1;	 // 지뢰로 설정
		else
			i--; // 지뢰이면 다시 설정
	}
}

int makeInfo() // 지뢰 주변 정보 저장 함수
{
	for (int j = 1; j <= H; j++) // (1,1)~(W,H)까지 탐색
		for (int i = 1; i <= W; i++)
			if (map[i][j] == 1) // 그 칸이 지뢰이면 -1
				info[i][j] = -1;
			else // 지뢰가 아니면 주변의 지뢰개수 저장
				info[i][j] = map[i - 1][j - 1] + map[i][j - 1] + map[i + 1][j - 1] + map[i - 1][j] + map[i + 1][j] + map[i - 1][j + 1] + map[i][j + 1] + map[i + 1][j + 1];
}

int gotoxy(int x, int y) // (x,y)로 커서 이동 함수
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int DFS(int x, int y) // 0인 칸을 선택한 경우
{
	if (y < 1 || y > H || x < 1 || x > W)
		return 0; // 맵 밖으로 벗어날 경우 종료
	if (visit[x][y] == 1)
		return 0; // 이전에 방문한 정점이면 종료
	else
	{
		cnt++;			 // 뒤집은 칸의 개수 증가
		visit[x][y] = 1; // (x,y) 방문을 체크
	}

	gotoxy(x * 2, y + 7);	  // 콘솔 창에서 (x,y)에 해당하는 위치로 커서 이동
	printf("%d", info[x][y]); // (x,y) 뒤집기

	if (info[x][y] == 0)
	{ // (x,y) 주변에 지뢰가 없으면 8방향 DFS
		DFS(x - 1, y - 1);
		DFS(x - 1, y);
		DFS(x - 1, y + 1);
		DFS(x, y - 1);
		DFS(x, y + 1);
		DFS(x + 1, y - 1);
		DFS(x + 1, y);
		DFS(x + 1, y + 1);
	}
}

int NUM(char x) // NUM(x) 함수 : 문자인 char x를 숫자인 int x로 바꿈.
{
	int tmp; // 임시 저장 변수
	if (x == '0')
		tmp = 0; // char x=0이면 tmp에 0값을 저장
	else if (x == '1')
		tmp = 1; // char x=1이면 tmp에 1값을 저장
	else if (x == '2')
		tmp = 2; // char x=2이면 tmp에 2값을 저장
	else if (x == '3')
		tmp = 3; // char x=3이면 tmp에 3값을 저장
	else if (x == '4')
		tmp = 4; // char x=4이면 tmp에 4값을 저장
	else if (x == '5')
		tmp = 5; // char x=5이면 tmp에 5값을 저장
	else if (x == '6')
		tmp = 6; // char x=6이면 tmp에 6값을 저장
	else if (x == '7')
		tmp = 7; // char x=7이면 tmp에 7값을 저장
	else if (x == '8')
		tmp = 8; // char x=8이면 tmp에 8값을 저장
	else if (x == '9')
		tmp = 9; // char x=9이면 tmp에 9값을 저장
	return tmp;	 // tmp값을 반환
}

int scanNUM() // scanNUM() 연산 : 숫자를 입력받음.
{
	int a = 0, b = 1, X = 0; // 스택 저장 변수, 자릿수를 나타내는 변수, 수를 나타내는 변수
	char x;					 // 문자 입력 변수
	while (1)
	{
		scanf("%c", &x); // x를 입력받음
		if (x == '\n')
		{ // 엔터를 입력받으면
			while (a >= 1)
			{ // a값이 1과 같거나 클 동안
				if (X == -1)
					return -1; // 문자가 입력되면 에러 코드 반환
				else
				{						// 아니면
					X = X + num[a] * b; // X값에 'num[a]값*자릿수'를 더함
					a--;				// a 포인터 1 감소
					b = b * 10;			// 자릿수가 1 증가함에 따라 곱해주는 수 10 증가
				}
			}
			return X; // X값 반환
		}
		else if (x == '0' || x == '1' || x == '2' || x == '3' || x == '4' || x == '5' || x == '6' || x == '7' || x == '8' || x == '9')
		{					 // x가 숫자이면
			a++;			 // a 포인터 1 증가
			num[a] = NUM(x); // num[a]값에 x값을 숫자로 변환해서 대입함
		}
		else
			X = -1; // 아니면(문자가 입력될 경우) 에러 코드 반환
	}
}

int F5() // F5() 연산 : 맵을 출력함
{
	gotoxy(0, 7); // (0,7)으로 커서 이동
	for (int b = 1; b <= H; b++)
	{				   // 세로 크기만큼 모두 작성할 때까지 반복
		printf("\n "); // 줄 바꿈
		for (int a = 1; a <= W; a++)
		{								   // 가로 크기만큼 모두 작성할 때까지 반복
			if (visit[a][b] == 1)		   // 뒤집었으면
				printf(" %d", info[a][b]); // 주변 지뢰 개수 출력
			else if (visit[a][b] == -1)	   // 지뢰로 메모했으면
				printf(" *");			   // "*"로 출력
			else
				printf(" ."); // 아니면 "."으로 출력
		}
	}
}

int main()
{
	while (1)
	{
		int RE = 0; // RE포인터 초기화
		cnt = 0;
		allCnt = 0;
		allMine = 0, leftMine = 0;	   // 모든 변수 값 초기화
		for (int a = 1; a <= 111; a++) // 모든 배열 값 초기화
			for (int b = 1; b <= 111; b++)
			{
				map[a][b] = 0;
				info[a][b] = 0;
				visit[a][b] = 0;
			}

		// 초기 설정 화면
		system("cls"); // 콘솔 화면을 다 지움
		printf("*********************************************************************\n");
		printf("*               지     뢰     찾     기     게     임               *\n");
		printf("*********************************************************************\n\n");

		printf("맵의 가로 크기를 입력하세요(10~75) : ");
		while (1)
		{
			W = scanNUM();
			if (10 <= W && W <= 75)
				break;
			else
				printf("범위를 벗어났습니다! 다시 입력해주세요(10~75) : ");
		}

		printf("맵의 세로 크기를 입력하세요(10~23) : ");
		while (1)
		{
			H = scanNUM();
			if (10 <= H && H <= 23)
				break;
			else
				printf("범위를 벗어났습니다! 다시 입력해주세요(10~23) : ");
		}

		printf("난이도를 선택하세요(1:초급, 2:중급, 3:고급) : ");
		while (1)
		{
			LV = scanNUM();
			if (1 <= LV && LV <= 3)
				break;
			else
				printf("범위를 벗어났습니다! 다시 입력해주세요(1~3) : ");
		}

		makeMap();	// 맵 생성
		makeInfo(); // 지뢰 주변 정보 저장

		// 게임 진행 루틴
		char c;			  // 키보드 입력 변수
		int x = 1, y = 1; // 초기 x,y좌표를 (1,1)로 설정

		system("cls"); // 콘솔 화면을 다 지움
		printf("\n *************** 지뢰 찾기 게임 ***************\n");
		printf("\n (Z : 칸 뒤집기) (X : 메모하기) (R : 새로고침)\n");

		F5(); // 맵 출력

		while (1)
		{
			gotoxy(0, 4);													  // (0,4)로 커서 이동
			printf("\n          게임 진행 시간 : ( %02d : %02d )", min, sec); // 두 자리 수의 형식으로 게임 진행 시간 출력
			printf("\n          남은 지뢰 개수 : ( %03d  개 )\n", leftMine);  // 세 자리 수의 형식으로 남아 있는 지뢰 개수 출력

			gotoxy(x * 2, y + 7); // 콘솔 창에서 (x,y)에 해당하는 위치로 커서 이동
			if (kbhit())
			{				 // 입력된 값이 있을 경우
				c = getch(); // 키보드 문자 입력 받기
				if (c == 224)
					c = getch(); // 224 문자 코드는 생략

				if (c == 72)
					y--; // ↓를 누를 시
				else if (c == 80)
					y++; // ↑를 누를 시
				else if (c == 75)
					x--; // ←를 누를 시
				else if (c == 77)
					x++; // →를 누를 시
				else if (c == 'r' || c == 'R')
					F5(); // 새로고침 버튼
				else if (c == 'x' || c == 'X')
				{ // 메모 버튼
					if (visit[x][y] == -1)
					{					 // (x,y)가 지뢰로 메모되어 있다면
						printf(".");	 // 다시 "."으로 바꾸어 출력
						leftMine++;		 // 남아 있는 지뢰 개수 1개 증가
						visit[x][y] = 0; // (x,y)의 방문 기록을 초기화함
					}
					else
					{					  // 그 외의 경우
						printf("*");	  // 지뢰로 표시
						leftMine--;		  // 남아 있는 지뢰 개수 1개 감소
						visit[x][y] = -1; // (x,y)를 지뢰로 표시했음을 배열에 저장함
					}
				}
				else if (c == 'z' || c == 'Z')
				{ // 뒤집기 버튼
					if (info[x][y] == -1)
					{						  // 지뢰인 경우
						printf("*");		  // 지뢰로 표시
						gotoxy(W * 2, H + 7); // 맵의 마지막 끝으로 커서 이동
						printf("\n\n GAME OVER");
						printf("\n\n R : 다시 시작 |  Q : 프로그램 종료");
						while (1)
						{
							c = getch(); // 문자 입력받기
							switch (c)
							{ // 입력받은 c값에 대해서
							case 'r':
							case 'R':
								RE = 1;
								break; // r을 입력받으면 RE포인터를 1로 설정하고 조건문 탈출
							case 'Q':
							case 'q':
								return 0; // q를 입력받으면 프로그램 종료
							default:
								continue; // 이외의 경우 다시 입력받음
							}
							if (RE == 1)
								break; // r을 입력받았을 경우 반복문 탈출
						}
					}
					else if (info[x][y] == 0)
					{			   // 주변 8칸 안에 지뢰가 없는 경우
						DFS(x, y); // 칸 펼치기
					}
					else
					{ // 주변 8칸 안에 지뢰가 있는 경우
						if (visit[x][y] == 1)
							continue;			  // 그 전에 눌렀던 칸이면 다시 입력받기
						printf("%d", info[x][y]); // 주변 지뢰 정보 출력
						cnt++;					  // 뒤집은 칸의 개수 증가
						visit[x][y] = 1;		  // (x,y)칸을 뒤집었음을 표시
					}
				}
				if (cnt == allCnt)
				{						  // 게임 승리 조건
					gotoxy(W * 2, H + 7); // 맵의 마지막 끝으로 커서 이동
					printf("\n\n 축 하 합 니 다 !!!");
					printf("\n\n R : 다시 시작 |  Q : 프로그램 종료");
					while (1)
					{
						c = getch(); // 문자 입력받기
						switch (c)
						{ // 입력받은 c값에 대해서
						case 'r':
						case 'R':
							RE = 1;
							break; // r을 입력받으면 RE포인터를 1로 설정하고 조건문 탈출
						case 'q':
						case 'Q':
							return 0; // q를 입력받으면 프로그램 종료
						default:
							continue; // 이외의 경우 다시 입력받음
						}
						if (RE == 1)
							break; // r을 입력받았을 경우 반복문 탈출
					}
				}
				if (RE == 1)
					break; // 게임 종료 화면에서 r을 입력받았을 경우 반복문 탈출
			}

			// 시간 측정 루틴
			Sleep(10); // 0.01초 대기
			tenms++;   // tenms값 1 증가
			if (tenms == 100)
			{			   // 1초가 되면
				sec++;	   // sec값 1 상승
				tenms = 0; // tenms값 초기화
			}
			if (sec == 60)
			{			 // 60초가 되면
				min++;	 // min값 1 상승
				sec = 0; // sec값 초기화
			}
		}
	}
}
