#include <iostream>
#include <vector>
#include <algorithm>
#define MAXSIZE 25
using namespace std;

void DFS(int x, int y, int map[MAXSIZE][MAXSIZE], bool check[MAXSIZE][MAXSIZE]);

int sumcnt = 0;
int danjicnt = 0;

int main()
{
	int N;

	cin >> N;

	int map[MAXSIZE][MAXSIZE];
	bool check[MAXSIZE][MAXSIZE];
	vector<int> danjisum;
	bool danjistart = false;

	for (int i = 0; i < MAXSIZE; i++)
	{
		for (int j = 0; j < MAXSIZE; j++)
		{
			map[i][j] = 0;
			check[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char tmp;
			cin >> tmp;
			map[i][j] = tmp - '0';
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1)
			{				
				DFS(i, j, map, check);
				danjicnt++;
				danjisum.push_back(sumcnt);
				sumcnt = 0;
			}
		}
	}

	cout << danjicnt << endl;

	sort(danjisum.begin(), danjisum.end());

	for (auto p : danjisum)
	{
		cout << p << endl;
	}
}

void DFS(int x, int y, int map[MAXSIZE][MAXSIZE], bool check[MAXSIZE][MAXSIZE])
{
	int dirX[4] = { -1,0,1,0 };
	int dirY[4] = { 0,1,0,-1 };
	
	map[x][y] = 0;
	check[x][y] = true;
	sumcnt++;

	for (int i = 0; i < 4; i++)
	{
		int cx = dirX[i] + x;
		int cy = dirY[i] + y;

		if (cx < 0 || cy <0 || cx >= MAXSIZE || cy >= MAXSIZE) continue;
		if (map[cx][cy] == 0) continue;	// 벽이면 무시
		if (check[cx][cy] == 1) { check[cx][cy] = true; continue; }// 이미 방문했다면 무시
		
		DFS(cx, cy, map, check);
	}
}