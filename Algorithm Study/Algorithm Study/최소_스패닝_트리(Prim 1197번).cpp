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

	// ��� ���� ���� 1
	vertexcnt++;
	vCheck[1] = true;
	while (vertexcnt < M)
	{
		// ��� ���� ����� ������ �ּҰ��� ���� �Ѵ�.
		// �� ���� �ּ� ���� ����Ǿ� ���� ���� ���̾�� �Ѵ�.
		for (int i = 0; i < M; i++)
		{

		}
	}


	return 0;
}