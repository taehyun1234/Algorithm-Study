// 다시 공부해볼것.https://steady-coding.tistory.com/18
#include <iostream>
using namespace std;
#define MAX_SQUARE 50000

int min(int a, int b);

int main()
{
	int dp[MAX_SQUARE];
	int curNum = 0;
	int answer = 0;

	dp[0] = 0;
	dp[1] = 1;

	cin >> curNum;

	for (int i = 1; i <= curNum; i++)
	{
		dp[i] = dp[1] + dp[i - 1];
		for (int j = 2; j * j <= i; j++)
		{
			dp[i] = min(dp[i], 1 + dp[i - j * j]);
		}
	}

	cout << dp[curNum];

	return 0;
}

int min(int a, int b)
{
	return a < b ? a : b;
}