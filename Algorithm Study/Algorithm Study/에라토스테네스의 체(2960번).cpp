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

	for (int i = 2; i <= n; i++)
	{
		l.push_back(i);
	}

	while (!bFinished)
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
		if (removeCnt == k)
		{
			answer = p;
			break;
		}

		for (list<int>::iterator it = l.begin(); it != l.end(); )
		{
			if (*it % p == 0)
			{
				int temp = *it;
				l.erase(it++);
				removeCnt++;
				if (removeCnt == k)
				{
					answer = temp;
					bFinished = true;
					break;
				}
			}
			else
			{
				it++;
			}
		}


	}

	cout << answer;


	return 0;
}