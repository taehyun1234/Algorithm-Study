#include <iostream>
using namespace std;

int main()
{
	// p(1) = 1
	// p(2) = 1
	// p(3) = 1
	// p(4) = 2 
	// p(5) = 2 = p(0) + p(4)
	// p(6) = 3 = p(1) + p(5)
	// p(7) = 4 = p(2) + p(6)
	// p[8) = 5 = p(3) + p(7)
	// p(9) = 7 = p(4) + p(8)
	// p(10) = 9 = p(5) + p(9)

	unsigned long pado[101];
	int N;

	cin >> N;

	pado[0] = 0;
	pado[1] = 1;
	pado[2] = 1;
	pado[3] = 1;
	pado[4] = 2;

	for (int i = 5; i < 101; i++)
	{
		pado[i] = pado[i - 5] + pado[i - 1];
	}


	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		cout << pado[tmp]<<endl;
	}


	return 0;
}