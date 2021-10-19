#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int dp[41];
	int testCase = 0;
	vector<pair<int, int>> answer;

	//	fibonacci(3)을 호출하면 다음과 같은 일이 일어난다.
	//
	//	fibonacci(3)은 fibonacci(2)와 fibonacci(1) (첫 번째 호출)을 호출한다.
	//	fibonacci(2)는 fibonacci(1) (두 번째 호출)과 fibonacci(0)을 호출한다.
	//	두 번째 호출한 fibonacci(1)은 1을 출력하고 1을 리턴한다.
	//	fibonacci(0)은 0을 출력하고, 0을 리턴한다.
	//	fibonacci(2)는 fibonacci(1)과 fibonacci(0)의 결과를 얻고, 1을 리턴한다.
	//	첫 번째 호출한 fibonacci(1)은 1을 출력하고, 1을 리턴한다.
	//	fibonacci(3)은 fibonacci(2)와 fibonacci(1)의 결과를 얻고, 2를 리턴한다.

	cin >> testCase;

	dp[0] = 0;
	dp[1] = 1;
	//																																																		0갯수, 1갯수, 피보나치수
	// fibonacci(0) = 0																																																1, 0, 0
	// fibonacci(1) = 1																																																0, 1, 1
	// fibonacci(2) = fibanacci(1) + fibonacci(0)																																								1, 1, 1
	// fibonacci(3) = fibonacci(2) + fibonacci(1) = fibonacci(1) + fibonacci(1) + fibonacci(0)																									1, 2, 2
	// fibonacci(4) = fibonacci(3) + fibonacci(2) = fibonacci(1) + fibonacci(1) + fibonacci(0) + fibanacci(1) + fibonacci(0)																2, 3, 3
	// fibonacci(5) = fibonacci(4) + fibonacci(3) = fibonacci(1) + fibonacci(1) + fibonacci(0) + fibanacci(1) + fibonacci(0) + fibonacci(1) + fibonacci(1) + fibonacci(0)		3, 5, 5
	// fibonacci(6) = fibonacci(5) + fibonacci[4] =																																							5, 8, 8
	// fibonacci(1) + fibonacci(1) + fibonacci(0) + fibanacci(1) + fibonacci(0) + fibonacci(1) + fibonacci(1) + fibonacci(0) + fibonacci(1) + fibonacci(1) + fibonacci(0) + fibanacci(1) + fibonacci(0)	

	for (int i = 2; i < 41; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	// 5 -> 3

	for (int i = 0; i < testCase; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp == 0)
		{
			answer.push_back(make_pair(1,0));
		}
		else if (tmp == 1)
		{
			answer.push_back(make_pair(0, 1));
		}
		else
		{
			answer.push_back(make_pair(dp[tmp-1], dp[tmp]));
		}
	}

	for (auto p : answer)
	{
		cout << p.first << " " << p.second << '\n';
	}

	return 0;
}