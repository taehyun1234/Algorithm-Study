#include <iostream>
using namespace std;

int main()
{

	int inputCnt = 0;
	int threeKg = 0;
	int fiveKg = 0;
	int remain = 0;

	cin >> inputCnt;

	fiveKg = inputCnt / 5;

	while (true)
	{
		if (fiveKg < 0)
		{
			break;
		}

		// 1. 5Ű��¥���� ���� �� ���, �׳� ������ ��.
		if ((inputCnt - fiveKg * 5) == 0)
		{
			break;
		}
		// 2. 5Ű��¥���� ���� ���� ������, ���� �����ִ� ������ 3Ű��¥���� �� ������ Ȯ��
		else
		{
			remain = inputCnt - fiveKg * 5;
			if (remain % 3 == 0)
			{
				// 3Ű��¥���� ����, ��. 
				inputCnt -= 3;
				threeKg++;
			}
			else
			{
				// �ȵ��ٸ�, ��ü�Ѵ�.
				fiveKg--;
			}
		}
	}

	int finalOutput = fiveKg + threeKg;
	if (finalOutput == 0)
	{
		finalOutput = -1;
	}

	cout << finalOutput;
	return 0;
}