#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> addVector;

	int N, M;

	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++)
	{
		int nTmp;
		cin >> nTmp;
		addVector.push_back(nTmp);
	}

	for (int i = 0; i < M; i++)
	{
		int nTmp1, nTmp2;

		cin >> nTmp1;
		cin >> nTmp2;
		int sum = 0;
		for (int k = nTmp1-1; k <= nTmp2-1; k++)
		{
			sum += addVector[k];
		}
		cout << sum << '\n';
	}

	return 0;
}
// 시간초과뜨니 다시해볼것.