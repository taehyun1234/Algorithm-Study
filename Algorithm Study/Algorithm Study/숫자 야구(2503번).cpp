#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


struct AttackInfo
{
	int number;
	int strike;
	int ball;

	static vector<AttackInfo> read()
	{
		vector<AttackInfo> result;

		string line;
		getline(cin, line);


		while (!line.empty())
		{
			AttackInfo info;
			stringstream ss(line);

			ss >> info.number;
			ss >> info.strike;
			ss >> info.ball;

			result.push_back(info);

			line.clear();
			getline(cin, line);
		}

		return result;
	}
};

int solution(vector<AttackInfo> baseball) {
	int answer = 0;
	string num1 = "";

	for (int i = 123; i <= 987; i++) {
		num1 = to_string(i);

		// �ߺ� ����, 0����
		{
			if (num1[0] == num1[1] || num1[0] == num1[2] || num1[1] == num1[2])
				continue;
			else if (num1[0] == '0' || num1[1] == '0' || num1[2] == '0')
				continue;
		}

		// ���⼭ ���� �ڵ� �ۼ� 
		// ���� ���ڰ� baseball �ȿ� ����ִ� ��� strike, ball�� ���� ���, �� ���ڴ� ���ɼ��� �ִٰ� �� �� �ִ�.
		// �׷��� �׳� Ž�� �ѹ� �ξ� �Ȱ� temp������ baseball ������ ������ ��� answer�� 1�� ���ϸ� ��.
		// ������ ������ �ð��� �����ؼ� ��Ǯ����.
		int temp = 0;
		for (int i = 0; i < baseball.size(); i++)
		{
			int strike = 0;
			int ball = 0;
			int _num1 = baseball[i].number / 100;
			int _num2 = (baseball[i].number % 100) / 10;
			int _num3 = (baseball[i].number % 100) % 10;
			
			if (num1[0] - '0' == _num1)
			{
				strike++;
			}
			if (num1[1] - '0' == _num2)
			{
				strike++;
			}
			if (num1[2] - '0' == _num3)
			{
				strike++;
			}

			if (num1[0] - '0' == _num2 || num1[0] - '0' == _num3)
			{
				ball++;
			}
			if (num1[1] - '0' == _num1 || num1[1] - '0' == _num3)
			{
				ball++;
			}
			if (num1[2] - '0' == _num1 || num1[2] - '0' == _num2)
			{
				ball++;
			}

			if (strike == baseball[i].strike && ball == baseball[i].ball)
			{
				temp++;
			}
		}
		if (temp == baseball.size() - 1)
		{
			answer++;
		}
	}

	return answer;
}

int main()
{
	auto info = AttackInfo::read();


	cout << solution(info);
	return 0;
}

