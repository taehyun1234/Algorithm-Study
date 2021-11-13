#include <iostream>
using namespace std;
#define VERTEX_MAX 10001
#define EDGE_MAX 100000

int main()
{
	int vertex[VERTEX_MAX][VERTEX_MAX];
	int M, N;

	cin >> M;
	cin >> N;

	for (int i = 0; i < VERTEX_MAX; i++)
	{
		for (int j = 0; j < VERTEX_MAX; j++)
		{
			vertex[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		int nTmp1, nTmp2, nTmp3;
		cin >> nTmp1 >> nTmp2 >> nTmp3;
		vertex[nTmp1][nTmp2] = nTmp3;
	}

	for (int i = 0; i < VERTEX_MAX; i++)
	{
		for (int j = 0; j < VERTEX_MAX; j++)
		{
			if (vertex[i][j] != 0)
				cout << i << "," << j << vertex[i][j] << endl;
		}
	}
	return 0;
}