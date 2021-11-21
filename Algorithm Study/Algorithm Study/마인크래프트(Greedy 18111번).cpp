#include <iostream>
#define MAX_GROUND 501
using namespace std;



int main()
{
	int M, N, B;			// M�� ����, N�� ����, B�� �κ��丮 �ȿ� �ִ� ����� ����
	int map[MAX_GROUND][MAX_GROUND];

	cin >> M >> N >> B;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int tmp;
			cin >> tmp;
			map[i][j] = tmp;
		}
	}
	// �Է� �Ϸ�

	// 1. ��ǥ i,j���� ����� �����Ͽ� �κ��丮�� �ִ´�.											-- �ð� 1��
	// 2. �κ��丮���� ��� �ϳ��� ������ ��ǥ i,j�� ���� ���� �ִ� ��� ���� ���´�.		-- �ð� 2��

	int minGround=99999, maxGround=-1;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (minGround > map[i][j])
			{
				minGround = map[i][j];
			}
			if (maxGround < map[i][j])
			{
				maxGround = map[i][j];
			}
		}
	}




	return 0;
}