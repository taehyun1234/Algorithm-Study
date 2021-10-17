#include <iostream>
#include <vector>
using namespace std;

int DFS();

int main()
{
	int N;

	cin >> N;

	vector<vector<int>> map(N,vector<int>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int tmp;
			cin >> tmp;
			map[i][j] = tmp;
		}
	}

}