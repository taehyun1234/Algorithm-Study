#include <iostream>
using namespace std;
#define MAX_NUM 1001
int main()
{
	int dp[MAX_NUM];
	int N;
	cin >> N;

	dp[1] = 1;		// 2x1
	dp[2] = 2;		// 2x1 + 2x1

	for (int i = 3; i < MAX_NUM; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2])%10007;
	}

	cout << dp[N] << endl;

	return 0;
}