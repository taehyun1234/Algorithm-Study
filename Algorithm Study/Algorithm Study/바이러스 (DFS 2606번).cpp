#include <iostream>
using namespace std;

#define MAX_COMPUTER 101

int computerMap[MAX_COMPUTER][MAX_COMPUTER];
bool check[MAX_COMPUTER];
int computers;
int connectLines;
int wormCnt;

void DFS(int idx);

int main()
{

	for (int i = 0; i < MAX_COMPUTER; i++)
	{
		check[i] = false;
		for (int j = 0; j < MAX_COMPUTER; j++)
		{
			computerMap[i][j] = 0;
		}
	}

	wormCnt = 0;

	cin >> computers;
	cin >> connectLines;

	for (int i = 0; i < connectLines; i++)
	{
		int tmpX, tmpY;
		cin >> tmpX >> tmpY;
		computerMap[tmpX-1][tmpY-1] = 1;
		computerMap[tmpY - 1][tmpX - 1] = 1;
	}

	// 1�� ��ǻ�Ͱ� ���� �ɷ�����, 1���� ����� ��� ��ǻ��(A)�� ������ �� ���̰�,
	// A�� ����� ��ǻ�� ���� ������ ���̴�.
	// 1 - A ->>> ����� ��ǻ�Ͱ� ���� ��쿡 üũ �س��� ���� �ε������� �˻�

	check[0] = true;
	DFS(0);

	cout << wormCnt << endl;

	return 0;
}


void DFS(int idx)
{
	for (int i = 0; i < computers; i++)
	{
		if (check[i] == true || computerMap[idx][i] == 0)
			continue;

		if (computerMap[idx][i] == 1 && check[i] == false)
		{
			wormCnt++;
			check[i] = true;
			DFS(i);
		}
	}
}