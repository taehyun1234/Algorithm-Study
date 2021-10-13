#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<string, int> dictionary;
	int nPocketMonCount = 0;
	int answerCount = 0;

	cin >> nPocketMonCount >> answerCount;

	for (int i = 0; i < nPocketMonCount; i++)
	{
		string tmp;
		cin >> tmp;
	}
	cout << endl<<endl;
	for (int i = 0; i < answerCount; i++)
	{
		string tmp;
		cin >> tmp;
		if (tmp[0] >= 'A' && tmp[0] <= 'Z')
		{
			// 이러면 문자임.
		}
		else
		{
			// 이러면 숫자.
		}
	}

	return 0;
}