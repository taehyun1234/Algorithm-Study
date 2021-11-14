#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bVisited[10001];
vector<pair<int, int>> edge[10001];

int PrimAlgorithm()
{
	int answer = 0;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;		// ū ������ �����ϴ� �켱����ť�� �����.
	// first�� ����ġ, second�� ������ minHeap

	pq.push(make_pair(0, 1));		// 1�� �������� ����, ����ġ�� ���� ���� ���Ұ� �� ���� ���� �ȴ�.
	
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top();			// ����ġ�� ���� ���� ���Ҹ� Ž���� ���̹Ƿ�, pq�� top�� �ȴ�.
		pq.pop();										// cur�� ����������, �̾Ƴ���.

		if (bVisited[cur.second] == true)		// �̹� �湮�� ���� �ִٸ�, �׳� �н��Ѵ�.
			continue;

		bVisited[cur.second] = true;				// �� ������ �Ȱ�������, �湮�� ���� ����.

		answer += cur.first;

		for (int i = 0; i < edge[cur.second].size(); i++)
		{
			if (!bVisited[edge[cur.second][i].second])		// ���� �������� �̵��� �� �ִ� ��� ������ ���� �湮���� �ʾҴٸ�, �湮�� ������� �߰����ش�.
			{
				pq.push(edge[cur.second][i]);
			}
		}
	}
	return answer;
}

int main()
{
	int nVertex, nEdge;
	cin >> nVertex >> nEdge;

	for (int i = 0; i < nEdge; i++)
	{
		int nTmp1, nTmp2, nTmp3;
		cin >> nTmp1 >> nTmp2 >> nTmp3;
		edge[nTmp1].push_back(make_pair(nTmp3, nTmp2));
		edge[nTmp2].push_back(make_pair(nTmp3, nTmp1));
	}
	int result = PrimAlgorithm();

	cout << result;
	return 0;
}
