#include <iostream>
#include <string>

using namespace std;

/*
어떤 자연수 N이 있을 때, 그 자연수 N의 분해합은 N과 N을 이루는 각 자리수의 합을 의미한다. 
어떤 자연수 M의 분해합이 N인 경우, M을 N의 생성자라 한다. 
예를 들어, 245의 분해합은 256(=245+2+4+5)이 된다. 
따라서 245는 256의 생성자가 된다. 물론, 어떤 자연수의 경우에는 생성자가 없을 수도 있다. 
반대로, 생성자가 여러 개인 자연수도 있을 수 있다.

자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구해내는 프로그램을 작성하시오.
*/

int main()
{
	int numberN = 0;
	string numberC="";
	int answer = 0;
	int result = 0;

	cin >> numberN;			// 1<=N<=1000000

	for (int i = 1; i <= numberN; i++)
	{
		// 각 자리의 숫자와 i를 더했을 때, numberN이 나올 경우 break걸고 빠져나오면 되는데
		// 각 자리(최대 6개)의 숫자를 구해주는게 포인트임.			   
		numberC = to_string(i);
		for (int i = 0; i < numberC.size(); i++)
		{
			result += numberC[i] - '0';
		}
		result += i;
		if (result == numberN)
		{
			answer = i;
			break;
		}
		else
		{
			result = 0;
		}
	}
	cout << answer<<endl;
	
	return 0;
}