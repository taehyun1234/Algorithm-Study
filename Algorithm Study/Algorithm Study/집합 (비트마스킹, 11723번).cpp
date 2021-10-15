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

	bool bCheck[20] = {false,};

	for (int i = 0; i < calcuCount; i++)
	{
		string strTmp;
		int nTmp;

		cin >> strTmp >> nTmp;

		if (strTmp == "add")
		{
			bCheck[nTmp - 1] = true;
		}
		else if (strTmp == "remove")
		{
			bCheck[nTmp - 1] = false;
		}
		else if (strTmp == "check")
		{
			if (bCheck[nTmp - 1])
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (strTmp == "toggle")
		{
			bCheck[nTmp-1] = ~bCheck[nTmp-1];
		}
		else if (strTmp == "all")
		{
			for (int i = 0; i < 20; i++)
			{
				bCheck[i] = 1;
			}
		}
		else if (strTmp == "empty")
		{
			for (int i = 0; i < 20; i++)
			{
				bCheck[i] = 0;
			}
		}
	}
	// 1111 1111 1111 1111 1111
}