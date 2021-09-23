#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int cnt;
void DFS(int x, int y, vector<vector<int>>& map, vector<vector<bool>>& ck);
int main()
{
	int input = 0;
	int temp = 0;
	cin >> input;

	vector<vector<int>> v(input, vector<int>());					// map
	vector<int> arr;														// ���� ���� ����
	vector<vector<bool>> check(input, vector<bool>());		// �湮�� �� üũ
	cnt = 1;

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			cin >> temp;
			v[i].push_back(temp);
			check[i].push_back(false);
		}
	}

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			if (v[i][j] == 1)
			{
				DFS(i, j, v, check);
				arr.push_back(cnt);
				cnt = 1;
			}
			else
			{
				continue;
			}
		}
	}

	sort(arr.begin(), arr.end());

	cout << arr.size() << endl;
	for (auto p : arr)
	{
		cout << p << " ";
	}

	return 0;
}

void DFS(int x, int y, vector<vector<int>>& map, vector<vector<bool>>& ck)
{
	int dirX[4] = { -1,0,1,0 };
	int dirY[4] = { 0,1,0,-1 };
	// �����¿� Ž��

	ck[x][y] = true;
	map[x][y] = 0;		// 0���� ����

	for (int i = 0; i < 4; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];
		//��,��,��,�� �̵� �� ������ �Ѿ�� ��� continue
		if (nextX < 0 || nextY < 0 || nextX >= ck.size() || nextY >= ck.size()) { continue; }
		//�湮�Ѱ��� continue
		if (ck[nextX][nextY]) { continue; }
		//0�� ���̶� �̵��� ��ΰ� ���̸� continue
		if (map[nextX][nextY] == 0) { ck[nextX][nextY] = true; continue; }

		DFS(nextX, nextY, map, ck);
		cnt++;
	}
}

