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
	
	// ���� ��ġ���� �����鼭, ���� ū �༮�� ���Ѵ�.
	
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
		// ���� ��ġ���� �����鼭 ���� ū���� ���ؼ� �׳��� ����.
		sum -= maxCoin;
		answer++;
	}

	cout << answer << endl;

	return 0;
}