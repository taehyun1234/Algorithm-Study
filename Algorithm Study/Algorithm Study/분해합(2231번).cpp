#include <iostream>
#include <string>

using namespace std;

/*
� �ڿ��� N�� ���� ��, �� �ڿ��� N�� �������� N�� N�� �̷�� �� �ڸ����� ���� �ǹ��Ѵ�. 
� �ڿ��� M�� �������� N�� ���, M�� N�� �����ڶ� �Ѵ�. 
���� ���, 245�� �������� 256(=245+2+4+5)�� �ȴ�. 
���� 245�� 256�� �����ڰ� �ȴ�. ����, � �ڿ����� ��쿡�� �����ڰ� ���� ���� �ִ�. 
�ݴ��, �����ڰ� ���� ���� �ڿ����� ���� �� �ִ�.

�ڿ��� N�� �־����� ��, N�� ���� ���� �����ڸ� ���س��� ���α׷��� �ۼ��Ͻÿ�.
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
		// �� �ڸ��� ���ڿ� i�� ������ ��, numberN�� ���� ��� break�ɰ� ���������� �Ǵµ�
		// �� �ڸ�(�ִ� 6��)�� ���ڸ� �����ִ°� ����Ʈ��.			   
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