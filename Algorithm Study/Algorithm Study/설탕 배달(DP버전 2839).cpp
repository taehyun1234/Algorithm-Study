#include <iostream>
#define MAX_KG 5000

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int dp[MAX_KG];

	int N;

	cin >> N;
	// 3키로 봉지와 5키로 봉지에 나눠 담아야함.

	for (int i = 0; i < MAX_KG; i++)
	{
		dp[i] = 99999;
	}

	dp[3] = 1;
	dp[5] = 1;
	// 3일때 1, 5일때 1

	for (int i = 6; i <= N; i++)
	{
		dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1) ;			// 이전의 dp케이스에 1을 더해주면 됨.
	}

	if (dp[N] > 99999)			// 만약 dp[N]이 99999보다 클 경우, 3,5의 배수가 아닌 것.
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << dp[N]<<'\n';
	}


	return 0;
}