#include <iostream>
#define MAX_GROUND 501
using namespace std;



int main()
{
	int M, N, B;			// M은 가로, N은 세로, B는 인벤토리 안에 있는 블록의 갯수
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