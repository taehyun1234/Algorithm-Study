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

		// 1. 5키로짜리에 전부 들어갈 경우, 그냥 끝내면 됨.
		if ((inputCnt - fiveKg * 5) == 0)
		{
			break;
		}
		// 2. 5키로짜리에 전부 들어가지 않으면, 현재 남아있는 설탕이 3키로짜리에 다 들어가는지 확인
		else
		{
			remain = inputCnt - fiveKg * 5;
			if (remain % 3 == 0)
			{
				// 3키로짜리에 들어가면, 굿. 
				inputCnt -= 3;
				threeKg++;
			}
			else
			{
				// 안들어간다면, 해체한다.
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