#include <stdio.h>

int n = 8;		 // 입력받는 정수의 개수 : 8개
int tree[8 * 4]; // 트리 배열(단말 노드가 최대 8개가 되므로 이보다 크게 잡아줌)

int max(int a, int b)
{				  // 최대값을 구하는 함수
	if (a > b)	  // a가 크면
		return a; // a 반환
	else		  // 아니면
		return b; // b 반환
}

int minus(int a, int b)
{				  // 최소값을 구하는 함수
	if (a < b)	  // b가 크면
		return a; // a 반환
	else		  // 아니면
		return b; // b 반환
}

int main() // 메인 함수
{
	int i, k;	   // 트리 저장 변수 i, 숫자 입력 변수 k
	int start = 8; // 트리에서 저장할 첫 번째 데이터 위치
	for (i = 0; i < n; i++)
	{
		scanf("%d", &k);	 // n개의 데이터 입력 받기
		tree[start + i] = k; // 트리의 시작위치부터 차례대로 데이터 구성
	}
	for (i = (start + n - 1) / 2; start / 2 <= i; i--) // 레벨 4에서
		tree[i] = max(tree[i * 2], tree[i * 2 + 1]);   // 큰 숫자를 찾음
	while (start / 4 <= i)
	{												   // 레벨 3에서
		tree[i] = minus(tree[i * 2], tree[i * 2 + 1]); // 작은 숫자를 찾음
		i--;										   // i값 1 감소
	}
	while (start / 8 <= i)
	{												 // 레벨 2에서
		tree[i] = max(tree[i * 2], tree[i * 2 + 1]); // 큰 숫자를 찾음
		i--;										 // i값 1 감소
	}
	printf("%d", tree[1]); // 루트 노드를 출력함
}

/*****************************************************
윤창호(장산중학교)
- 제출일 : 2015.11.3
- 소스코드 설명
	각 레벨별로 반복문을 작성해서 자식 노드 중 조건에 맞는 노드를
	부모 노드에 저장하는 방식으로 진행해서 최종적으로 루트 노드를 출력했습니다.
- 성찰 일지
	아직은 트리 알고리즘이 어색하네요.
*****************************************************/
