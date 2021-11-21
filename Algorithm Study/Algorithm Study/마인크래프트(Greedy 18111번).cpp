#include <iostream>
#define MAX_GROUND 501
using namespace std;



int main()
{
	int M, N, B;			// M은 가로, N은 세로, B는 인벤토리 안에 있는 블록의 갯수
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
	// 입력 완료

	// 1. 좌표 i,j위의 블록을 제거하여 인벤토리에 넣는다.											-- 시간 1초
	// 2. 인벤토리에서 블록 하나를 꺼내어 좌표 i,j의 가장 위에 있는 블록 위에 놓는다.		-- 시간 2초

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