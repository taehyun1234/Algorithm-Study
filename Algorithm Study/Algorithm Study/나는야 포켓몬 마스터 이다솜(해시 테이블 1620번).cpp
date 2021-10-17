/*
#include <iostream>
#include <vector>
#include <map>
#include <string>


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<string, int> dictionary;
	map<int,string> strDictionary;
	vector<string> answer;

	int nPocketMonCount = 0;
	int answerCount = 0;

	cin >> nPocketMonCount >> answerCount;

	for (int i = 0; i < nPocketMonCount; i++)
	{
		string tmp;
		cin >> tmp;
		dictionary.insert(make_pair(tmp, i));
		strDictionary.insert(make_pair(i,tmp));
	}
	
	for (int i = 0; i < answerCount; i++)
	{
		string tmp;
		cin >> tmp;
		if (tmp[0] >= 'A' && tmp[0] <= 'Z')
		{
			// 이러면 문자임. -> 숫자로 출력
			int ans = (*dictionary.find(tmp)).second + 1;
			cout << ans <<endl;
//			answer.push_back(to_string(ans));
		}
		else
		{
			// 25->문자로
			int ntmp = stoi(tmp) - 1;
			string ans = (*strDictionary.find(ntmp)).second;
			cout << ans << endl;
//			answer.push_back(stmp);
		}
	}
//	for (auto p : answer)
//	{
//		cout << p << endl;
//	}

	return 0;
}
*/

// 위의 방법은 시간초과로 뜸. -> 단순한 해시테이블이 아님.
// 밑의 방법은 시간초과가 뜨지 않음.
// 별로 다를게 없는데.. 왜?
// cin, cout, endl과 같은 입출력 경우 시간초과가 나오는 경우가 많음. 그래서 sync_with_stdio를 쓰던지 그냥 printf,scanf 쓰면됨.

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	// 숫자 인덱스를 이용해 문자열을 가져오기 위한 벡터
	vector<string> v;
	// 문자열을 키로 사용해 숫자를 가져오기 위한 맵(딕셔너리)
	map<string, int> _map;

	cin >> n >> m;
	int ansIdx;
	string ansStr;
	string name;
	// 포켓몬들 정보 입력 부분
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		v.push_back(name);
		_map.insert(pair<string, int>(name, i + 1));
	}

	for (int i = 0; i < m; i++)
	{
		cin >> ansStr;
		// 만약 입력된 문자열이 숫자라면
		if (atoi(ansStr.c_str()))
		{
			// 숫자로 바꿔준다음 해당 인덱스로 값을 출력
			ansIdx = stoi(ansStr);
			cout << v[ansIdx - 1] << '\n';
		}
		// 숫자가 아닐 경우 맵의 키값으로 사용하여 번호 출력
		else
		{
			cout << _map[ansStr] << '\n';
		}
	}
}