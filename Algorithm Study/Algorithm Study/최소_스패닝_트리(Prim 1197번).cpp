#include <iostream>
using namespace std;
#define VERTEX_MAX 10001
#define EDGE_MAX 100000

int vertex[VERTEX_MAX][VERTEX_MAX];
bool vCheck[VERTEX_MAX];
int main()
{
	int M, N;
	int vertexcnt = 0;
	int answer = 0;

	cin >> M;
	cin >> N;

	for (int i = 0; i < VERTEX_MAX; i++)
	{
		vCheck[i] = false;
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

	// 출발 정점 설정 1
	vertexcnt++;
	vCheck[1] = true;
	while (vertexcnt < M)
	{
		// 모든 점과 연결된 간선의 최소값을 골라야 한다.
		// 이 때의 최소 값은 연결되어 있지 않은 값이어야 한다.
		for (int i = 0; i < M; i++)
		{

		}
	}


	return 0;
}