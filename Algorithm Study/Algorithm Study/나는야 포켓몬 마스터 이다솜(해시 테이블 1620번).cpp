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
			// �̷��� ������. -> ���ڷ� ���
			int ans = (*dictionary.find(tmp)).second + 1;
			cout << ans <<endl;
//			answer.push_back(to_string(ans));
		}
		else
		{
			// 25->���ڷ�
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

// ���� ����� �ð��ʰ��� ��. -> �ܼ��� �ؽ����̺��� �ƴ�.
// ���� ����� �ð��ʰ��� ���� ����.
// ���� �ٸ��� ���µ�.. ��?
// cin, cout, endl�� ���� ����� ��� �ð��ʰ��� ������ ��찡 ����. �׷��� sync_with_stdio�� ������ �׳� printf,scanf �����.

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
	// ���� �ε����� �̿��� ���ڿ��� �������� ���� ����
	vector<string> v;
	// ���ڿ��� Ű�� ����� ���ڸ� �������� ���� ��(��ųʸ�)
	map<string, int> _map;

	cin >> n >> m;
	int ansIdx;
	string ansStr;
	string name;
	// ���ϸ�� ���� �Է� �κ�
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		v.push_back(name);
		_map.insert(pair<string, int>(name, i + 1));
	}

	for (int i = 0; i < m; i++)
	{
		cin >> ansStr;
		// ���� �Էµ� ���ڿ��� ���ڶ��
		if (atoi(ansStr.c_str()))
		{
			// ���ڷ� �ٲ��ش��� �ش� �ε����� ���� ���
			ansIdx = stoi(ansStr);
			cout << v[ansIdx - 1] << '\n';
		}
		// ���ڰ� �ƴ� ��� ���� Ű������ ����Ͽ� ��ȣ ���
		else
		{
			cout << _map[ansStr] << '\n';
		}
	}
}