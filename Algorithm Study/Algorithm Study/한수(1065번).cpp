#include <iostream>
using namespace std;

/*한수
어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. 
N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.
*/

// 입력 : 첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.


int main()
{
	int inputNum = 0;
	cin >> inputNum;

	// 한수의 경우, 등차수열인걸 봐야한다.
	// 근데, 사실상 둘째자리 숫자까지만 있다면 무조건 등차수열이 될 수 밖에 없다.

	int answer = 0;

	for (int i = 1; i <= inputNum; i++)
	{
		// 둘째자리까지는 모두 더하기
		// 셋째자리에서부터는 판단을 다르게 해주어야 함.
		if (i < 100)
		{
			answer++;
		}
		else if(i < 1000 && i >= 100)
		{
			int numH = i / 100;
			int numT = (i % 100) / 10;
			int numO = (i % 100) % 10;

			if (numH - numT == numT - numO)
			{
				answer++;
			}
		}
	}

	cout << answer;

	return 0;
}