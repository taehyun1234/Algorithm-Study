#include <iostream>
#include <vector>
using namespace std;

void QuadTreePrint(int n, int x, int y, vector<vector<int>> map);

int main()
{
	int N;

	cin >> N;

	vector<vector<int>> map(N,vector<int>(N));
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char tmp;
			cin >> tmp;
			map[i][j] = tmp - '0';
		}
	}

	/*
	���� ��, ������ ��, ���� �Ʒ�, ������ �Ʒ� 4���� ���� ��, �ϳ��� ���ڷ�
	�̷���� ���� ��� �� ���ڸ� ���, �ƴ� ��� �ٽ� 4���� ������ ���	
	*/
	QuadTreePrint(N, 0, 0, map);
	cout << endl;

	return 0;
}

void QuadTreePrint(int n, int x, int y, vector<vector<int>> map)
{
	int div = n / 2;
	int cx = 0, cy = 0;
	bool check;

	for (int i = 0; i < 4; i++)
	{
		// ���� ������ ���� ��, ������ ��, ���� �Ʒ�, ������ �Ʒ�
		if (i == 0)
		{
			cx = x;
			cy = y;
		}
		else if (i == 1)
		{
			cx = x + div;
			cy = y;
		}
		else if (i == 2)
		{
			cx = x;
			cy = y + div;
		}
		else
		{
			cx = x + div;
			cy = y + div;
		}

		int check = map[cx][cy];
		bool bBreak = false;

		for (int j = 0; j < div; j++)
		{
			for (int k = 0; k < div; k++)
			{
				if (map[j][k] != check)
				{
					QuadTreePrint(div, cx, cy, map);
					bBreak = true;
					break;
				}
			}
			if (bBreak == true)
				break;
		}
		// �ش� �����ȿ� ��� ���ڰ� ���� ������ �ٽ� �����־����.
		if (bBreak == false)
			cout << check;
	}
	cout << ")";
}