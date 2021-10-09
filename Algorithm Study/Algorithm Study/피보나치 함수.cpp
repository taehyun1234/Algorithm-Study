#include <iostream>
#include <vector>

using namespace std;

int dp[41];

int fibonacci(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else 
	{
		return dp[n] + dp[n - 1];
	}
}

int main()
{
	int testCase = 0;
	vector<int> input;
	vector<pair<int, int>> output;

	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int temp;
		cin >> temp;
		input.push_back(temp);
	}

	for (int i = 0; i < testCase; i++)
	{
		zero = 0;
		one = 0;
		fibonacci(input[i]);
		cout << zero << " " << one<<endl;
	}

	return 0;
}