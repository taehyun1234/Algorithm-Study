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
	vector<int> arr;														// 영역 넓이 저장
	vector<vector<bool>> check(input, vector<bool>());		// 방문한 곳 체크
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
	// 상하좌우 탐색

	ck[x][y] = true;
	map[x][y] = 0;		// 0으로 설정

	for (int i = 0; i < 4; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];
		//상,하,좌,우 이동 중 범위가 넘어서는 경우 continue
		if (nextX < 0 || nextY < 0 || nextX >= ck.size() || nextY >= ck.size()) { continue; }
		//방문한곳은 continue
		if (ck[nextX][nextY]) { continue; }
		//0은 벽이라서 이동할 경로가 벽이면 continue
		if (map[nextX][nextY] == 0) { ck[nextX][nextY] = true; continue; }

		DFS(nextX, nextY, map, ck);
		cnt++;
	}
}

