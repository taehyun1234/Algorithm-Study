#include <iostream>
#include <vector>
using namespace std;
#define MAX_FLOOR 300

int Max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int floorCnt = 0;
	int floors[MAX_FLOOR];
	int dp[MAX_FLOOR];

	cin >> floorCnt;

	for (int i = 0; i < floorCnt; i++)
	{
		int tmp;
		cin >> tmp;
		floors[i] = tmp;
	}


	// 한번에 한계단 혹은 두계단 오를 수 잇음.
	// 연속된 세 개의 계단을 모두 밟으면 안됨.
	// 마지막 도착 계단은 반드시 밟아야 함.
	
	dp[0] = floors[0];															// 첫번째 계단을 올라가는 경우는 단 한가지 밖에 없음.
	dp[1] = floors[0] + floors[1];											// 두번째 계단을 올라가는 경우는 연속으로 두 계단 올라 가거나, 한번에 가는 경우인데, 두계단 올라가는게 더 클 수밖에 없음.
	dp[2] = Max(floors[0] + floors[2], floors[1] + floors[2]);			// 세번째 계단을 올라가는 경우는 첫번째 계단을 밟고 세번째 계단을 밟거나, 두번째 계단을 밟고 세번째 계단을 밟는 경우 두가지다. 그 중 큰 놈으로 결정

	for (int i = 3; i < floorCnt; i++)
	{
		dp[i] = Max(dp[i - 2] + floors[i], floors[i - 1] + floors[i] + dp[i - 3]);
		// 전전칸 까지의 최대 값 + 현재칸					-- floors[i] + dp[i-2]
		// 전전전칸 까지의 최대 값 + 전칸 + 현재칸		-- floors[i] + floors[i - 1]+ dp[i-3]
		// 둘 중 더 큰 녀석으로 저장.
	}

	/*
	Dynamic Programming의 핵심인 Memoization과 점화식을 기억해둬야 한다.
	https://kwanghyuk.tistory.com/4
	*/

	cout << dp[floorCnt - 1]<<'\n';

	return 0;
}