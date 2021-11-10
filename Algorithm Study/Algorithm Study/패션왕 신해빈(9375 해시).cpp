#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	int testCase = 0;
	unordered_map<string, int> wear;
	cin >> testCase;



	for (int i = 0; i < testCase; i++)
	{
		int count = 0;

		cin >> count;
		wear.clear();
		for (int j = 0; j < count; j++)
		{
			string strTmp1, strTmp2;
			cin >> strTmp1 >> strTmp2;
			if (wear.find(strTmp2) == wear.end())			// find�Լ��� ����ؼ� �������� ���� ���, ��ã�Ҵٴ� ��.
			{
				wear.insert(make_pair(strTmp2, 1));
			}
			else
			{
				wear[strTmp2]++;
			}
		}
		int answer = 1;
		for (auto p : wear)
		{
			answer *= (p.second + 1);
		}

		cout << answer - 1 << endl;

	}

	return 0;
}