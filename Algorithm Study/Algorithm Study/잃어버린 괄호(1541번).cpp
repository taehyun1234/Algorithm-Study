#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string str;
	vector<int> num;			// 숫자
	vector<char> sign;		// 부호

	cin >> str;

	for (int i = 0;i<str.size();i++)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			sign.push_back(str[i]);
		}
		else
		{
			num.push_back(str[i] - '0');
		}
	}


	for (auto p : num)
	{
		cout << p << endl;
	}
}