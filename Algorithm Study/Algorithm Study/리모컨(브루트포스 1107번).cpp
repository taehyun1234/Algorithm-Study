#include <iostream>
#include <algorithm>
using namespace std;

bool bBroken[10];					// 고장난 버튼

// case 1. 단순히 +, -를 사용하는 경우
int CaseFirst(int nChannel, int nBrokenbuttonCount)
{
	if (nChannel >= 100)
		return nChannel - 100;
	else
		return 100 - nChannel;
}

int press(int t)
{
	// 누를 수 있는 채널인지 체크 + 자릿수 반환
	if (t == 0)		// 예외 0일 때
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

// ----------------------------------------------------------- 다시 봐야할 부분 - Case Second, press https://suhwanc.tistory.com/13
// case 2. 숫자를 입력한 후 +, - 를 사용하는 경우
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
	int nowChannel = 100;			// 현재 보고있는 채널

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
	현재 채널(100번)에서 +/- 버튼만을 이용하여 이동하려는 채널 N까지 가는 경우 ex) 98, 99, 101, 102 와 같이 숫자를 누르는 것보다 +, -로 가는 것이 더 빠른 경우

	case 2.
	채널 N에서 최대한 가까운 채널의 숫자 버튼을 누른 후 +/- 버튼을 이용하는 경우
	*/

	int answer = min(CaseFirst(nChannel, nBrokenbuttonCount), CaseSecond(nChannel,nBrokenbuttonCount));

	cout << answer;

	return 0;
}