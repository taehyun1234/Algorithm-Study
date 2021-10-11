#include <iostream>
#include <vector>

using namespace std;

int dp[41] = { 0,1,1 };

int fibonacci(int n) {
	if (n == 0 || n == 1)
		return dp[n];
	if (dp[n] == 0) {			
		dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
	return dp[n];
}

// 0 1 1 2 3 5 8 13 21 34 55

int main()
{
	int testCase = 0;
	vector<int> input;

	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int temp;
		cin >> temp;
		input.push_back(temp);
	}

	for (int i = 0; i < testCase; i++)
	{
		if (i != 0)
			cout << fibonacci(input[i-1]) << " " << fibonacci(input[i])<<endl;
		else
			cout << "1 0"<<endl;
	}

	return 0;
}