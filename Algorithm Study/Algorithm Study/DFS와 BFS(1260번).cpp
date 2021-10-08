#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1000 + 1;
int N, M, V;
int adjacent[MAX][MAX];
bool visited[MAX];

queue<int> q;

void DFS(int idx)
{
	cout << idx << " ";

	for (int i = 0; i < N; i++)
	{
		if (adjacent[idx][i+1] && !visited[i+1])
		{
			visited[i+1] = true;
			//������ ��忡 ���ؼ� �� �ٽ� DFS
			DFS(i+1);
		}
	}
}



void BFS(int idx)
{
	q.push(idx);
	visited[idx] = 1;

	while (!q.empty())
	{
		idx = q.front();
		q.pop();

		cout << idx << " ";
		//BFS�� �ش� ��忡 ������ ������ ��� �߰��� �� BFS ����

		for (int i = 0; i < N; i++)
		{
			if (adjacent[idx][i+1] && !visited[i+1])	
			{	
				visited[i+1] = true;	
				q.push(i+1);	
			}
		}
	}
}



int main(void)
{
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		adjacent[from][to] = 1;
		adjacent[to][from] = 1;
	}

	visited[V] = 1; //V���� �����ϹǷ�
	DFS(V);
	cout << endl;

	memset(visited, false, sizeof(visited));
	BFS(V);
	cout << endl;

	return 0;

}
