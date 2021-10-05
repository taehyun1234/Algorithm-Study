#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
�� ���� ȸ�ǽ��� �ִµ� �̸� ����ϰ��� �ϴ� N���� ȸ�ǿ� ���Ͽ� ȸ�ǽ� ���ǥ�� ������� �Ѵ�. 
�� ȸ�� I�� ���� ���۽ð��� ������ �ð��� �־��� �ְ�, �� ȸ�ǰ� ��ġ�� �ʰ� �ϸ鼭 ȸ�ǽ��� ����� �� �ִ� ȸ���� �ִ� ������ ã�ƺ���.
��, ȸ�Ǵ� �ѹ� �����ϸ� �߰��� �ߴܵ� �� ������ �� ȸ�ǰ� ������ �Ͱ� ���ÿ� ���� ȸ�ǰ� ���۵� �� �ִ�. 
ȸ���� ���۽ð��� ������ �ð��� ���� ���� �ִ�. �� ��쿡�� �������ڸ��� ������ ������ �����ϸ� �ȴ�.
*/


int main()
{
	vector<pair<int, int>> arr;
	int maxMeeting;

	cin >> maxMeeting;
		
	for (int i = 0; i < maxMeeting; i++)
	{
		int end, start;
		cin >> start >> end;
		arr.push_back({end, start	});
		// ������ �켱 �ؾ� �� ��. -> end�� �������� �༮�� ������ �����ؾ� �ϹǷ�, end�� �տ����´�.
	}	
	
	sort(arr.begin(), arr.end());
	// ���� ��, end�� ���� �ռ��ź��� �޿�...�ִµ�, ���� ��ġ�� out

	int answer = 1;
	int finishTime = arr[0].first;
	for (int i = 1; i < arr.size(); i++)
	{
		if (finishTime > arr[i].second)
		{
			continue;
		}
		else
		{
			finishTime = arr[i].first;
			answer++;
		}
	}
	cout << answer<<endl;

	return 0;
}