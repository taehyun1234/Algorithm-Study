#include <iostream>
using namespace std;

int main()
{
	int r1, r2, r3;

	while (true)
	{		
		cin >> r1 >> r2 >> r3;
		if (r1 == 0 && r2 == 0 && r3 == 0)
		{
			break;
		}

		if ((r1 * r1 + r2 * r2 == r3 * r3) ||
			(r1 * r1 + r3 * r3 == r2 * r2) ||
			(r3 * r3 + r2 * r2 == r1 * r1))
		{
			cout << "right" << endl;
		}
		else
		{
			cout << "wrong" << endl;
		}
	}

	return 0;
}