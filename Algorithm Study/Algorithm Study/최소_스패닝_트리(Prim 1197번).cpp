#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bVisited[10001];
vector<pair<int, int>> edge[10001];

int PrimAlgorithm()
{
	int answer = 0;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;		// 큰 순서로 정렬하는 우선순위큐를 만든다.
	// first는 가중치, second는 정점의 minHeap

	pq.push(make_pair(0, 1));		// 1번 정점부터 시작, 가중치가 가장 작은 원소가 맨 위로 가게 된다.
	
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top();			// 가중치가 가장 작은 원소를 탐색할 것이므로, pq의 top이 된다.
		pq.pop();										// cur에 저장했으니, 뽑아낸다.

		if (bVisited[cur.second] == true)		// 이미 방문한 적이 있다면, 그냥 패스한다.
			continue;

		bVisited[cur.second] = true;				// 위 구문을 안거쳤으니, 방문한 적이 없다.

		answer += cur.first;

		for (int i = 0; i < edge[cur.second].size(); i++)
		{
			if (!bVisited[edge[cur.second][i].second])		// 현재 정점에서 이동할 수 있는 모든 정점에 대해 방문하지 않았다면, 방문할 목록으로 추가해준다.
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
