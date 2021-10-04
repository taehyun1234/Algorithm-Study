#include <iostream>
#include <vector>
using namespace std;

/*
ī���뿡�� ���� �α� �ִ� ���� ������ ��Ģ�� ����� ����. ī���� ���� 21�� ���� �ʴ� �ѵ� ������, ī���� ���� �ִ��� ũ�� ����� �����̴�. ������ ī���븶�� �پ��� ������ �ִ�.

�ѱ� �ְ��� ���� ��� �������� ���ο� ���� ��Ģ�� ����� ���, â���̿� �����Ϸ��� �Ѵ�.

������ ������ ���迡�� �� ī�忡�� ���� ������ ���� �ִ�. �� ����, ������ N���� ī�带 ��� ���ڰ� ���̵��� �ٴڿ� ���´�. �׷� �Ŀ� ������ ���� M�� ũ�� ��ģ��.

���� �÷��̾�� ���ѵ� �ð� �ȿ� N���� ī�� �߿��� 3���� ī�带 ���� �Ѵ�. ���� ���� �����̱� ������, �÷��̾ �� ī���� ���� M�� ���� �����鼭 M�� �ִ��� ������ ������ �Ѵ�.

N���� ī�忡 ���� �ִ� ���ڰ� �־����� ��, M�� ���� �����鼭 M�� �ִ��� ����� ī�� 3���� ���� ���� ����Ͻÿ�.
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

	// ��� ����� ���� ���� ���� �ڿ�, �� ���� ���ؼ� ���� ����� ���� ã�Ƴ����� �ؾ���.

	for (int i = 0; i < vCards.size(); i++)
	{
		for (int j = 0; j < vCards.size(); j++)
		{
			for (int k = 0; k < vCards.size(); k++)
			{
				if (i == j || j == k || i == k)		// ���� �޶�� ��.
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
