#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string str;
	vector<int> num;			// ����
	vector<char> sign;		// ��ȣ

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