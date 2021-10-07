#include <iostream>
#include <list>
using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;
	list<int> l;
	int removeCnt = 0;
	int answer = 0;
	bool bFinished = false;

	for (int i = 2; i < n; i++)
	{
		l.push_back(i);
	}

	while (bFinished)
	{
		int p = 999999;
		for (auto x : l)
		{
			if (p > x)
			{
				p = x;
			}
		}
		// 가장 작은 수를 찾는다.

		l.remove(p);
		removeCnt++;
		if (removeCnt == n)
		{
			answer = p;
			bFinished = true;
			break;
		}

		for (auto x : l)
		{
			if (x / p == 0)
			{
				l.remove(x);
				removeCnt++;
				if (removeCnt == n)
				{
					answer = x;
					bFinished = true;
					break;
				}
			}
		}

		
	}

	cout << answer;


	return 0;
}