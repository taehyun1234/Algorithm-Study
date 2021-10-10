#include <iostream>
#include <vector>
#define MAX_WIDTH 50
#define MAX_HEIGHT 50

using namespace std;

void DFS(int x,int y, int map[MAX_WIDTH][MAX_HEIGHT], bool check[MAX_WIDTH][MAX_HEIGHT])
{
	int dirX[4] = { -1,0,1,0 };
	int dirY[4] = { 0,1,0,-1 };

	check[x][y] = true;
	map[x][y] = 0;
	// check되었으면 true로 바꾸고, map을 0으로 바꿈.

	for (int i = 0; i < 4; i++)
	{
		int nextX = dirX[i] + x;
		int nextY = dirY[i] + y;

		if (nextX < 0 || nextY < 0 || nextX >= MAX_WIDTH || nextY >= MAX_HEIGHT) { continue; }
		if (check[nextX][nextY]) { continue; }
		if (map[nextX][nextY] == 0) { check[nextX][nextY] = true; continue; }
		DFS(nextX, nextY, map, check);
	}
}

int main()
{
	int testCaseCount = 0;
	int maxWidth = 0;
	int maxHeight = 0;
	int locationCount = 0;

	cin >> testCaseCount;

	int map[MAX_WIDTH][MAX_HEIGHT];
	bool check[MAX_WIDTH][MAX_HEIGHT];

	int wormsCount = 0;
	vector<int> answer;

	for (int i = 0; i < testCaseCount; i++)
	{
		wormsCount = 0;
		cin >> maxWidth >> maxHeight >> locationCount;

		for (int j = 0; j < MAX_WIDTH; j++)
		{
			for (int k = 0; k < MAX_WIDTH; k++)
			{
				map[j][k] = 0;
				check[j][k] = false;
			}
		}

		for (int j = 0; j < locationCount; j++)
		{
			int tmpX,  tmpY;
			cin >> tmpX >> tmpY;
			if (tmpX < 0 || tmpX > MAX_WIDTH || tmpY < 0 || tmpY > MAX_HEIGHT)
			{
				continue;
			}
			else
			{
				map[tmpX][tmpY] = 1;
			}
		}

		for (int j = 0; j < maxWidth; j++)
		{
			for (int k = 0; k < maxHeight; k++)
			{
				if (map[j][k] == 1)
				{
					DFS(j, k, map, check);
					wormsCount++;
				}
			}
		}
		answer.push_back(wormsCount);
	}

	for (auto p : answer)
	{
		cout << p << endl;
	}
	return 0;
}