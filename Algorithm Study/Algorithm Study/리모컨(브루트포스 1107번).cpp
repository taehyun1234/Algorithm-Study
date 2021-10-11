#include <iostream>
#include <algorithm>
using namespace std;

bool bBroken[10];					// ���峭 ��ư

// case 1. �ܼ��� +, -�� ����ϴ� ���
int CaseFirst(int nChannel, int nBrokenbuttonCount)
{
	if (nChannel >= 100)
		return nChannel - 100;
	else
		return 100 - nChannel;
}

int press(int t)
{
	// ���� �� �ִ� ä������ üũ + �ڸ��� ��ȯ
	if (t == 0)		// ���� 0�� ��
	{
		if (bBroken[0]) return 0;
		else return 1;
	}
	else
	{
		int len = 0;
		while (t)
		{
			int tmp = t % 10;
			if (bBroken[tmp]==true) return 0;
			len++;
			t /= 10;
		}
		return len;
	}
}

// ----------------------------------------------------------- �ٽ� ������ �κ� - Case Second, press https://suhwanc.tistory.com/13
// case 2. ���ڸ� �Է��� �� +, - �� ����ϴ� ���
int CaseSecond(int nChannel, int nBrokenbuttonCount)
{
	int answer = 999999;

	for (int i = 0; i <= 1000000; i++)
	{
		int tmp = i;
		int len = press(tmp);
		if (len > 0)
		{
			int press = tmp - nChannel;
			if (press < 0) press = -press;
			if (answer > len + press)
			{
				answer = len + press;
			}
		}
	}
	return answer;
}


int main()
{
	memset(bBroken, false, sizeof(bBroken));

	int nChannel;
	int nBrokenbuttonCount;
	int nowChannel = 100;			// ���� �����ִ� ä��

	cin >> nChannel;
	cin >> nBrokenbuttonCount;

	for(int i = 0; i < nBrokenbuttonCount; i++)
	{
		int tmp;
		cin >> tmp;
		bBroken[tmp] = true;
	}

	/*
	case 1.
	���� ä��(100��)���� +/- ��ư���� �̿��Ͽ� �̵��Ϸ��� ä�� N���� ���� ��� ex) 98, 99, 101, 102 �� ���� ���ڸ� ������ �ͺ��� +, -�� ���� ���� �� ���� ���

	case 2.
	ä�� N���� �ִ��� ����� ä���� ���� ��ư�� ���� �� +/- ��ư�� �̿��ϴ� ���
	*/

	int answer = min(CaseFirst(nChannel, nBrokenbuttonCount), CaseSecond(nChannel,nBrokenbuttonCount));

	cout << answer;

	return 0;
}