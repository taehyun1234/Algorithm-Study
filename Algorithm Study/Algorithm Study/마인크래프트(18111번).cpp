#include <iostream>
#define MAX_GROUND 501
using namespace std;



int main()
{
	int M, N, B;			// M�� ����, N�� ����, B�� �κ��丮 �ȿ� �ִ� ����� ����
	int map[MAX_GROUND][MAX_GROUND];

	cin >> M >> N >> B;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int tmp;
			cin >> tmp;
			map[i][j] = tmp;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << map[i][j];
		}
		cout <<endl;
	}


	return 0;
}