#include <iostream>

#define MAX_COUNT 1000001

using namespace std;

int dp[MAX_COUNT];

int min(int a, int b)
{
	return a > b ? b : a;
}

int main()
{
	int answer = 0;
	dp[0] = 0;
	dp[1] = 0;												// �ƹ��͵� ����.

	// dp[n] = dp[n/3] + 1;					// 3���� ������������ ���
	// dp[n] = dp[n/2] + 1;					// 2�� ������������ ���
	// dp[n] = dp[n-1] + 1;					// 1�� ���� ���

	for (int i = 2; i <= MAX_COUNT; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
	}
	cin >> answer;

	cout << dp[answer];

	return 0;
}