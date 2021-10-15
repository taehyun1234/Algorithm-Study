#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, string> sitePassward;
	vector<string> answer;

	int M = 0, N = 0;

	cin >> M >> N;

	for (int i = 0; i < M; i++)
	{
		string strSite;
		string strPassward;

		cin >> strSite >> strPassward;
		sitePassward.insert(make_pair(strSite, strPassward));
	}

	for (int i = 0; i < N; i++)
	{
		string strTmp;
		cin >> strTmp;
		answer.push_back(sitePassward.at(strTmp));
	}

	for (auto p : answer)
	{
		cout << p << endl;
	}

	return 0;
}