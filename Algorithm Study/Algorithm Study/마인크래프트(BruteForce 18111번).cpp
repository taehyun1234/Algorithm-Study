#include <iostream>
#define MAX_GROUND 501
using namespace std;



int main()
{
	int M, N, B;			// M�� ����, N�� ����, B�� �κ��丮 �ȿ� �ִ� ����� ����
	int map[MAX_GROUND][MAX_GROUND];
	int total = 0;		// ���� ��� ������ ��

	cin >> M >> N >> B;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int tmp;
			cin >> tmp;
			map[i][j] = tmp;
			total += tmp;
		}
	}
	// �Է� �Ϸ�

	// 1. ��ǥ i,j���� ����� �����Ͽ� �κ��丮�� �ִ´�.											-- �ð� 1��
	// 2. �κ��丮���� ��� �ϳ��� ������ ��ǥ i,j�� ���� ���� �ִ� ��� ���� ���´�.		-- �ð� 2��

	// ��� ��츦 ���� ���ؼ�, �ð��� ������ �� ���� ���� ����� ���̸� ������ָ� �ȴ�. + �ð��� ���
	int time = 99999;
	int height = static_cast<int>(total / (N*M));
	int answerHeight = 0;
	if (height > 256) height = 256;
	
	while (height >= 0)
	{
		int curTime = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] <= height) curTime += (height - map[i][j]);
				else curTime += (2 * (map[i][j] - height));
			}
		}
		if (curTime < time)
		{
			time = curTime;
			answerHeight = height;
		}
		height--;
	}
	cout << time << " " << answerHeight;


	return 0;
}