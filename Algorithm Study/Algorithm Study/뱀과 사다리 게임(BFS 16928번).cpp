#include <iostream>
#include <queue>
// 뱀과 사다리를 굳이 구별할 필요가 없음. 그냥 하나로 할 것.

using namespace std;
#define MAX_NUMBER 15
#define MAP_SIZE 101

int N, M;
int nLadder[MAX_NUMBER];
int nLadderTarget[MAX_NUMBER];
int nSnake[MAX_NUMBER];
int nSnakeTarget[MAX_NUMBER];
bool bCheck[MAP_SIZE];

int BFS();

int main()
{	
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		nLadder[i] = tmp1;
		nLadderTarget[i] = tmp2;
	}

	for (int i = 0; i < M; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		nSnake[i] = tmp1;
		nSnakeTarget[i] = tmp2;
	}
	int answer = BFS();

	cout << answer;
}

int BFS()
{
	queue<pair<int,int>> q;

	q.push(make_pair(1, 0));

	while (!q.empty())
	{
		int curPt = q.front().first;
		int curDepth = q.front().second;

		q.pop();
		if (curPt == 100)
			return curDepth;

		for (int i = 0; i < N; i++)
		{
			if (nLadder[i] == curPt)
			{
				q.push(make_pair(nLadderTarget[i], curDepth + 1));
				bCheck[curPt] = true;
			}
			else
			{
				for (int j = 0; j < 6; j++)
				{
					if (bCheck[curPt+j] == false && curPt + j + 1 <= MAP_SIZE)
					{
						q.push(make_pair(curPt + j + 1, curDepth + 1));
						bCheck[curPt+j] = true;
					}
				}
			}
		}

		for (int i = 0; i < M; i++)
		{
			if (nSnake[i] == curPt)
			{
				q.push(make_pair(nSnakeTarget[i], curDepth + 1));
				bCheck[curPt] = true;
			}
			else
			{
				for (int j = 0; j < 6; j++)
				{
					if (bCheck[curPt+j] == false && curPt + j + 1 <= MAP_SIZE)
					{
						q.push(make_pair(curPt + j + 1, curDepth + 1));
						bCheck[curPt+j] = true;
					}
				}
			}
		}

	}
}