#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int answer = 0;
	int typeCount;
	int sum;
	vector<int> typeOfCoins;
	cin >> typeCount >> sum;
	

	for (int i = 0; i < typeCount; i++)
	{
		int tmp;
		cin >> tmp;
		typeOfCoins.push_back(tmp);
	}
	
	// 현재 가치보다 작으면서, 가장 큰 녀석을 구한다.
	
	while (true)
	{
		if (sum <= 0)
		{
			break;
		}

		int maxCoin = 0;

		for (int i = 0; i < typeCount; i++)
		{
			if (maxCoin < typeOfCoins[i])
			{
				if (typeOfCoins[i] <= sum) 
				{
					maxCoin = typeOfCoins[i];
				}
			}
		}
		// 현재 가치보다 작으면서 가장 큰놈을 구해서 그놈을 뺀다.
		sum -= maxCoin;
		answer++;
	}

	cout << answer << endl;

	return 0;
}