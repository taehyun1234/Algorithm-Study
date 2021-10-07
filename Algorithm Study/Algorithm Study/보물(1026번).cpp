#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int numCnt = 0;

	cin >> numCnt;

	vector<int> numA;
	vector<int> numB;

	for (int i = 0; i < numCnt; i++)
	{
		int tmp;
		cin >> tmp;
		numA.push_back(tmp);
	}

	for (int i = 0; i < numCnt; i++)
	{
		int tmp;
		cin >> tmp;
		numB.push_back(tmp);
	}

	sort(numA.begin(), numA.end(), greater<int>());
	sort(numB.begin(), numB.end(), less<int>());

	int sum = 0;

	for (int i = 0; i < numCnt; i++)
	{
		sum += numA[i] * numB[i];
	}

	cout << sum;

	return 0;
}