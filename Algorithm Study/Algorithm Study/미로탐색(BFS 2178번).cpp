#include <iostream>
#include <queue>
using namespace std;
#define MAX_ROW 101
#define MAX_COL 101

//https://cocoon1787.tistory.com/115 BFS�̷к��� �ٽ� �� �����غ� ��.

int check[MAX_ROW][MAX_COL];		// ������������ �Ÿ� ** �갡 �߿���.
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
	queue<pair<int, int>> q;		// ť
	q.push(make_pair(x, y));			// �������� ť�� ����.

	int dirX[4] = { -1,0,1,0 };
	int dirY[4] = { 0,-1,0,1 };

	while(!q.empty())					// ť�� �����Ͱ� ���� �� ����
	{
		int x = q.front().first;			// ť�� �� �տ� �ִ� ������ -> ť = FIFO ��, �� ó���� ���� �����͸� ����
		int y = q.front().second;

		q.pop();							// ť�� �� �տ� �ִ� �����͸� ������.
		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dirX[i];
			int nextY = y + dirY[i];

			if (nextX < 0 || nextX > MAX_ROW || nextY < 0 || nextY > MAX_COL)		// ������ ��� ���
				continue;

			if (map[nextX][nextY] == 1 && visit[nextX][nextY] == false)		// ���� �ְ�, �湮�ߴ� ���� ���� ���.
			{
				check[nextX][nextY] = check[x][y] + 1;
				visit[nextX][nextY] = true;
				q.push(make_pair(nextX, nextY));
			}
		}
	}
}