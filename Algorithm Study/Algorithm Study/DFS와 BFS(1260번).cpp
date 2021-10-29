#include <iostream>
#include <queue>
using namespace std;
#define MAX_VERTEX 1001
#define MAX_LINE 10001

int N;			// 정점의 갯수
int M;			// 간선의 갯수
int v;			// 방문 vertex
int bVertex[MAX_VERTEX][MAX_VERTEX];
int dVertex[MAX_VERTEX][MAX_VERTEX];
bool bCheck[MAX_VERTEX];

void BFS();
void DFS(int x);

int main()
{
	cin >> N >> M >> v;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			bVertex[i][j] = 0;
			dVertex[i][j] = 0;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		bVertex[tmp1][tmp2] = 1;
		bVertex[tmp2][tmp1] = 1;
		dVertex[tmp1][tmp2] = 1;
		dVertex[tmp2][tmp1] = 1;
	}

	DFS(v);

	cout << endl;
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		bCheck[i] = false;
	}

	BFS();

	return 0;
}

void DFS(int x)
{
	cout << x<<" ";
	bCheck[x] = true;
	for (int i = 0; i <= N; i++)
	{
		if (bCheck[i] == true || dVertex[x][i] == 0)
			continue;

		if (dVertex[x][i] == 1 && bCheck[i] == false)
		{
			dVertex[x][i] = 0;
			dVertex[i][x] = 0;
			bCheck[i] = true;
			DFS(i);
		}
	}
}

void BFS()
{
	queue<int> q;
	
	q.push(v);

	cout << v<<" ";

	while (!q.empty())
	{
		int idx = q.front();

		q.pop();

		for (int i = 0; i <= N; i++)
		{
			if (bVertex[idx][i] == 1 && bCheck[i] == false)
			{
				q.push(i);
				bVertex[idx][i] = 0;
				bVertex[i][idx] = 0;
				bCheck[i] = true;
				cout << i << " ";
			}
		}
	}
}
