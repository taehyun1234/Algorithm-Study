#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int M;
	map<string,int> nohear;
	vector<string> answer;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string strTmp;
		cin >> strTmp;
		nohear.insert(make_pair(strTmp,1));
	}

	for (int i = 0; i < M; i++)
	{
		string strTmp;
		cin >> strTmp;
		if (nohear[strTmp] == 1)
		{
			answer.push_back(strTmp);
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size()<<endl;
	for (auto p : answer)
	{
		cout << p << endl;
	}


	return 0;
}