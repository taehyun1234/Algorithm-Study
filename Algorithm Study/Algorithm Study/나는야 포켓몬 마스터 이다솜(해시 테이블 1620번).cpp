#include <iostream>
#include <vector>
#include <map>
#include <string>


using namespace std;

int main()
{
	map<string, int> dictionary;
	vector<string> strDictionary;
	vector<string> answer;

	int nPocketMonCount = 0;
	int answerCount = 0;

	cin >> nPocketMonCount >> answerCount;

	for (int i = 0; i < nPocketMonCount; i++)
	{
		string tmp;
		cin >> tmp;
		dictionary.insert(make_pair(tmp, i));
		strDictionary.push_back(tmp);
	}
	
	for (int i = 0; i < answerCount; i++)
	{
		string tmp;
		cin >> tmp;
		if (tmp[0] >= 'A' && tmp[0] <= 'Z')
		{
			// 이러면 문자임. -> 숫자로 출력
			int ans = dictionary[tmp]+1;
			answer.push_back(to_string(ans));
		}
		else
		{
			// 25->문자로
			int tm = stoi(tmp);
			string ans = strDictionary[tm-1];			
			answer.push_back(ans);
		}
	}
	for (auto p : answer)
	{
		cout << p << endl;
	}

	return 0;
}