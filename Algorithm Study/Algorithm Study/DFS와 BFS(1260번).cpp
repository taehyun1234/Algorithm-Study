#include <iostream>
#include <queue>
using namespace std;
#define MAX_VERTEX 1001
#define MAX_LINE 10001

int N;			// 정점의 갯수
int M;			// 간선의 갯수
int v;			// 방문 vertex
int vertex[MAX_VERTEX][MAX_VERTEX];
bool bCheck[MAX_VERTEX][MAX_VERTEX];

int main()
{
	cin >> N >> M >> v;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			vertex[i][j] = 0;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		vertex[tmp1][tmp2] = 1;
		vertex[tmp2][tmp1] = 1;
	}

	return 0;
}

int DFS()
{

}

int BFS()
{
	queue<int> q;
	
	q.push(v);

	while (!q.empty())
	{
		int idx = q.front();

		q.pop();

		for (int i = 0; i < N; i++)
		{
			if (vertex[idx][i] == 1 && bCheck[idx][i] == false)
			{
				q.push(i);
				bCheck[idx][i] = true;
			}
		}
	}
}