#include <iostream>
#include <queue>
using namespace std;
#define MAX_ROW 101
#define MAX_COL 101

//https://cocoon1787.tistory.com/115 BFS이론부터 다시 싹 공부해볼 것.

int check[MAX_ROW][MAX_COL];		// 시작점부터의 거리 ** 얘가 중요함.
int map[MAX_ROW][MAX_COL];
int visit[MAX_ROW][MAX_COL];

void BFS(int x,int y);

int main()
{
	int row, col;
	
	cin >> row >> col;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			char tmp;
			cin >> tmp;
			map[i][j] = tmp - '0';
		}
	}

	BFS(0, 0);

	cout << check[row-1][col-1] + 1;

	return 0;
}

void BFS(int x, int y)
{
	queue<pair<int, int>> q;		// 큐
	q.push(make_pair(x, y));			// 시작점을 큐에 삽입.

	int dirX[4] = { -1,0,1,0 };
	int dirY[4] = { 0,-1,0,1 };

	while(!q.empty())					// 큐에 데이터가 없을 때 까지
	{
		int x = q.front().first;			// 큐의 맨 앞에 있는 데이터 -> 큐 = FIFO 즉, 맨 처음에 들어온 데이터를 뽑음
		int y = q.front().second;

		q.pop();							// 큐의 맨 앞에 있는 데이터를 빼버림.
		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dirX[i];
			int nextY = y + dirY[i];

			if (nextX < 0 || nextX > MAX_ROW || nextY < 0 || nextY > MAX_COL)		// 범위를 벗어날 경우
				continue;

			if (map[nextX][nextY] == 1 && visit[nextX][nextY] == false)		// 길이 있고, 방문했던 적이 없는 경우.
			{
				check[nextX][nextY] = check[x][y] + 1;
				visit[nextX][nextY] = true;
				q.push(make_pair(nextX, nextY));
			}
		}
	}
}