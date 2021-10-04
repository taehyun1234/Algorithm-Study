#include <iostream>
#include <vector>
using namespace std;

/*
카지노에서 제일 인기 있는 게임 블랙잭의 규칙은 상당히 쉽다. 카드의 합이 21을 넘지 않는 한도 내에서, 카드의 합을 최대한 크게 만드는 게임이다. 블랙잭은 카지노마다 다양한 규정이 있다.

한국 최고의 블랙잭 고수 김정인은 새로운 블랙잭 규칙을 만들어 상근, 창영이와 게임하려고 한다.

김정인 버전의 블랙잭에서 각 카드에는 양의 정수가 쓰여 있다. 그 다음, 딜러는 N장의 카드를 모두 숫자가 보이도록 바닥에 놓는다. 그런 후에 딜러는 숫자 M을 크게 외친다.

이제 플레이어는 제한된 시간 안에 N장의 카드 중에서 3장의 카드를 골라야 한다. 블랙잭 변형 게임이기 때문에, 플레이어가 고른 카드의 합은 M을 넘지 않으면서 M과 최대한 가깝게 만들어야 한다.

N장의 카드에 써져 있는 숫자가 주어졌을 때, M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 구해 출력하시오.
*/

int main()
{
	int cntOfCard = 0;
	int maxNum = 0;
	vector<int> vCards;
	vector<int> vCardsAdd;

	cin >> cntOfCard >> maxNum;

	for (int i = 0; i < cntOfCard; i++)
	{
		int tmp;
		cin >> tmp;
		vCards.push_back(tmp);
	}

	// 모든 경우의 수를 전부 더한 뒤에, 그 수에 대해서 가장 가까운 수를 찾아내도록 해야함.

	for (int i = 0; i < vCards.size(); i++)
	{
		for (int j = 0; j < vCards.size(); j++)
		{
			for (int k = 0; k < vCards.size(); k++)
			{
				if (i == j || j == k || i == k)		// 전부 달라야 함.
				{
					continue;
				}
				else
				{
					int tmp;
					tmp = vCards[i] + vCards[j] + vCards[k];
					vCardsAdd.push_back(tmp);
				}
			}
		}
	}

	int minDistance = 99999;
	int minCardsAdd = 0;

	for (int i = 0; i < vCardsAdd.size(); i++)
	{
		if (vCardsAdd[i] <= maxNum)
		{
			if (minDistance > maxNum - vCardsAdd[i])
			{
				minDistance = maxNum - vCardsAdd[i];
				minCardsAdd = vCardsAdd[i];
			}
		}
	}

	cout << minCardsAdd;

	return 0;
}
