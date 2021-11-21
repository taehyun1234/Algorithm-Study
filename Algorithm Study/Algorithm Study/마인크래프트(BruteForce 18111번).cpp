#include <iostream>
#define MAX_GROUND 501
using namespace std;



int main()
{
	int M, N, B;			// M은 가로, N은 세로, B는 인벤토리 안에 있는 블록의 갯수
	int map[MAX_GROUND][MAX_GROUND];
	int total = 0;		// 맵의 모든 높이의 합

	cin >> M >> N >> B;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int tmp;
			cin >> tmp;
			map[i][j] = tmp;
			total += tmp;
		}
	}
	// 입력 완료

	// 1. 좌표 i,j위의 블록을 제거하여 인벤토리에 넣는다.											-- 시간 1초
	// 2. 인벤토리에서 블록 하나를 꺼내어 좌표 i,j의 가장 위에 있는 블록 위에 놓는다.		-- 시간 2초

	// 모든 경우를 전부 구해서, 시간과 구했을 때 가장 작은 경우의 높이를 출력해주면 된다. + 시간도 출력
	int time = 99999;
	int height = static_cast<int>(total / (N*M));
	int answerHeight = 0;
	if (height > 256) height = 256;
	
	while (height >= 0)
	{
		int curTime = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] <= height) curTime += (height - map[i][j]);
				else curTime += (2 * (map[i][j] - height));
			}
		}
		if (curTime < time)
		{
			time = curTime;
			answerHeight = height;
		}
		height--;
	}
	cout << time << " " << answerHeight;


	return 0;
}