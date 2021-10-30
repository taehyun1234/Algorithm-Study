#include <iostream>
#include <queue>
// 뱀과 사다리를 굳이 구별할 필요가 없음. 그냥 하나로 할 것.
#define MAX_NUMBER 15
#define MAP_SIZE 101

using namespace std;

int map[MAP_SIZE];

int ladder[MAP_SIZE];
bool bCheck[MAP_SIZE];
int directMapCnt;
int BFS();

int main()
{
	int answer;
	int N, M;
	cin >> N >> M;
	directMapCnt = N + M;

	for (int i = 0; i < directMapCnt; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		ladder[tmp1] = tmp2;
	}

	answer = BFS();
	cout << answer;
}

int BFS()
{
	queue<pair<int,int>> q;
	q.push({ 1,0 });
	bCheck[1] = true;

	while (!q.empty())
	{
		int curpt = q.front().first;
		int rollCnt = q.front().second;

		q.pop();

		if (curpt == 100)
			return rollCnt;

		for (int i = 1; i <= 6; i++)
		{
			int nextPos = curpt + i;
			if (bCheck[nextPos] == false && nextPos <MAP_SIZE)
			{
				if (ladder[nextPos] != 0)
				{
					nextPos = ladder[nextPos];
				}

				q.push({ nextPos ,rollCnt + 1 });
				bCheck[nextPos] = true;
			}
		}
	}
}

//2 1
//2 60
//30 98
//65 25
// 1 1 1 