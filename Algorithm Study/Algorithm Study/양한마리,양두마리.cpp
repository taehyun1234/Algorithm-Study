#include <iostream>
#include <vector>
using namespace std;

void DFS(int x, int y, int arr[100][100], bool ck[100][100], int width, int height);

int main()
{
	int testCase = 0;
	int width = 0, height = 0;	
	int arr[100][100];
	bool check[100][100];
	vector<int> answer;
	int cnt;
	cin >> testCase;

	for (int k = 0; k < testCase; k++)
	{
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				arr[i][j] = 0;
				check[i][j] = false;
			}
		}
		cnt = 0;

		cin >> width >> height;

		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				char temp;
				cin >> temp;
				if (temp == '#')
				{
					arr[i][j] = 1;
				}
				else
				{
					arr[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				if (arr[i][j] == 1)
				{
					DFS(i, j, arr, check, width, height);
					cnt++;
				}
				else
				{
					continue;
				}
			}
		}
		answer.push_back(cnt);
	}

	for (auto p : answer)
	{
		cout << p << endl;
	}

}

// 만약 이어져 있을 경우 하나로 보면 됨.

void DFS(int x,int y,int arr[100][100], bool ck[100][100], int width, int height)
{
	int dirX[4] = { -1,0,1,0 };
	int dirY[4] = { 0,1,0,-1 };

	ck[x][y] = true;
	arr[x][y] = 0;

	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX < 0 || nextY < 0 || nextX >= width || nextY >= height)	{continue;}
		if (ck[nextX][nextY]) { continue; }
		if (arr[nextX][nextY] == 0) { ck[nextX][nextY] = true; continue; }
		// 3개의 경우를 모두 걸렀으면, 이제부터 시작

		DFS(nextX, nextY, arr, ck, width, height);
	}

}