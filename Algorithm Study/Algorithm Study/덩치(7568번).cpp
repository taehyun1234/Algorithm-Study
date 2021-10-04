#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int numOfPeople;
	vector<int> weight;
	vector<int> height;
	vector<int> rank;

	cin >> numOfPeople;

	for (int i = 0; i < numOfPeople; i++)
	{
		int tmpW;
		int tmpH;

		cin >> tmpW >> tmpH;
		weight.push_back(tmpW);
		height.push_back(tmpH);
	}

	for (int i = 0;i<numOfPeople;i++)
	{
		int tmp = 1;
		for (int j = 0; j < numOfPeople; j++)
		{
			if(weight[i] < weight[j] && height[i] < height[j])
			{
				tmp++;
			}
		}
		rank.push_back(tmp);
	}

	for (int i = 0; i < rank.size(); i++)
	{
		cout << rank[i]<<" ";
	}


	return 0;
}