#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
�պ� ���� �ϰ� �����̵�� �Բ� ��ȭ�Ӱ� ��Ȱ�ϰ� �ִ� �鼳���ֿ��� ���Ⱑ ã�ƿԴ�. �ϰ��� ��ġ�� ���ƿ� �����̰� �ϰ� ���� �ƴ� ��ȩ ���̾��� ���̴�.

��ȩ ���� �����̴� ��� �ڽ��� "�鼳 ���ֿ� �ϰ� ������"�� ���ΰ��̶�� �����ߴ�. �پ ������ �������� ������ �ִ� �鼳���ִ�, ���ེ���Ե� �ϰ� �������� Ű�� ���� 100�� ���� ����� �´�.

��ȩ �������� Ű�� �־����� ��, �鼳���ָ� ���� �ϰ� �����̸� ã�� ���α׷��� �ۼ��Ͻÿ�.
*/

int main()
{
	vector<int> height;
	vector<int> answer;

	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		int tmp = 0;
		cin >> tmp;
		sum += tmp;
		height.push_back(tmp);
	}

	// 9���� 7���� �̾Ƽ� 7�� �� ���� ���� 100�� �ǵ��� �Ѵ�. -> 9���� ���� ������ 2���� ���� �� 100�� �ǵ��� �ϸ� �ȴ�.

	int eraseFirst;
	int eraseSecond;
	bool answerAll = false;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i == j)
			{
				continue;
			}
			else
			{
				if (sum - height[i] - height[j] == 100)
				{
					eraseFirst = height[i];
					eraseSecond = height[j];
					for (int k = 0; k < 9; k++)
					{
						if (height[k] == eraseFirst || height[k] == eraseSecond)
						{
							continue;
						}
						answer.push_back(height[k]);
						answerAll = true;
					}
					break;
				}
			}
		}
		if (answerAll == true)
			break;
	}

	sort(answer.begin(), answer.end());

	for (auto p : answer)
	{
		cout << p << endl;
	}
		 
	return 0;
}