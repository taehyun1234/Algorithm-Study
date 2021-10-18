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


	// �ѹ��� �Ѱ�� Ȥ�� �ΰ�� ���� �� ����.
	// ���ӵ� �� ���� ����� ��� ������ �ȵ�.
	// ������ ���� ����� �ݵ�� ��ƾ� ��.
	
	dp[0] = floors[0];															// ù��° ����� �ö󰡴� ���� �� �Ѱ��� �ۿ� ����.
	dp[1] = floors[0] + floors[1];											// �ι�° ����� �ö󰡴� ���� �������� �� ��� �ö� ���ų�, �ѹ��� ���� ����ε�, �ΰ�� �ö󰡴°� �� Ŭ ���ۿ� ����.
	dp[2] = Max(floors[0] + floors[2], floors[1] + floors[2]);			// ����° ����� �ö󰡴� ���� ù��° ����� ��� ����° ����� ��ų�, �ι�° ����� ��� ����° ����� ��� ��� �ΰ�����. �� �� ū ������ ����

	for (int i = 3; i < floorCnt; i++)
	{
		dp[i] = Max(dp[i - 2] + floors[i], floors[i - 1] + floors[i] + dp[i - 3]);
		// ����ĭ ������ �ִ� �� + ����ĭ					-- floors[i] + dp[i-2]
		// ������ĭ ������ �ִ� �� + ��ĭ + ����ĭ		-- floors[i] + floors[i - 1]+ dp[i-3]
		// �� �� �� ū �༮���� ����.
	}

	/*
	Dynamic Programming�� �ٽ��� Memoization�� ��ȭ���� ����ص־� �Ѵ�.
	https://kwanghyuk.tistory.com/4
	*/

	cout << dp[floorCnt - 1]<<'\n';

	return 0;
}