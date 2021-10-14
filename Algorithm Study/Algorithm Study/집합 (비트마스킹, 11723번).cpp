#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int calcuCount = 0;
	
	cin >> calcuCount;

	int bitmask = 0;

	for (int i = 0; i < calcuCount; i++)
	{
		string strTmp;
		int nTmp;

		cin >> strTmp >> nTmp;

		if (strTmp == "add")
		{
			bitmask |= (1 << nTmp);
		}
		else if (strTmp == "remove")
		{
			bitmask = bitmask & (~nTmp);		
		}
		else if (strTmp == "check")
		{
			if (bitmask & (1 << nTmp))
				cout << 1 << endl;
			else
				cout << 0 << endl; 
		}
		else if (strTmp == "toggle")
		{
			bitmask ^= (1 << nTmp);
		}
		else if (strTmp == "all")
		{
			bitmask = (1<<21)  - 1;
		}
		else if (strTmp == "empty")
		{
			bitmask = 0;
		}
	}
	// 1111 1111 1111 1111 1111
}