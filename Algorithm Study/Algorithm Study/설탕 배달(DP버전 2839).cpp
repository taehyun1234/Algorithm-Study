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
	// 3Ű�� ������ 5Ű�� ������ ���� ��ƾ���.

	for (int i = 0; i < MAX_KG; i++)
	{
		dp[i] = 99999;
	}

	dp[3] = 1;
	dp[5] = 1;
	// 3�϶� 1, 5�϶� 1

	for (int i = 6; i <= N; i++)
	{
		dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1) ;			// ������ dp���̽��� 1�� �����ָ� ��.
	}

	if (dp[N] > 99999)			// ���� dp[N]�� 99999���� Ŭ ���, 3,5�� ����� �ƴ� ��.
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << dp[N]<<'\n';
	}


	return 0;
}