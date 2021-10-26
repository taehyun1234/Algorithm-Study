#include <iostream>
#include <queue>
using namespace std;
#define MAX_POINT 100001

bool check[MAX_POINT];

int BFS(int cur, int target)
{
	int answer = 0;
	queue<pair<int,int>> q;

	q.push(make_pair(cur,0));

	while (!q.empty())
	{
		int curPt = q.front().first;
		int depth = q.front().second;

		q.pop();
		if (curPt == target)
		{
			answer = depth;
			break;
		}
		if (curPt * 2 < MAX_POINT)
		{
			if ((curPt * 2 < MAX_POINT && curPt * 2 > 0) && check[curPt * 2] == false)
			{
				q.push(make_pair(curPt * 2, depth + 1));
				check[curPt * 2] = true;
			}
		}
		if (curPt + 1 < MAX_POINT)
		{
			if ((curPt + 1 < MAX_POINT && curPt + 1 > 0)&& check[curPt + 1] == false)
			{
				q.push(make_pair(curPt + 1, depth + 1));
				check[curPt + 1] = true;
			}
		}
		if (curPt - 1 < MAX_POINT)
		{
			if ((curPt - 1 < MAX_POINT && curPt - 1 > 0) && check[curPt - 1] == false)
			{
				q.push(make_pair(curPt - 1, depth + 1));
				check[curPt - 1] = true;
			}
		}
	}
	return answer;
}

int main()
{
	// 걸을 경우 x - 1, x + 1
	// 순간이동  2*x 
	for (int i = 0; i < MAX_POINT; i++)
	{
		check[i] = false;
	}

	ios::sync_with_stdio(0);
	cin.tie(0);
	int current;
	int target;

	cin >> current >> target;
	check[current] = true;
	int answer = BFS(current, target);

	cout << answer;

	return 0;
}