#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의에 대하여 회의실 사용표를 만들려고 한다. 
각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고, 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수를 찾아보자.
단, 회의는 한번 시작하면 중간에 중단될 수 없으며 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다. 
회의의 시작시간과 끝나는 시간이 같을 수도 있다. 이 경우에는 시작하자마자 끝나는 것으로 생각하면 된다.
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
		// 정렬을 우선 해야 할 듯. -> end가 먼저오는 녀석을 순으로 정렬해야 하므로, end를 앞에놓는다.
	}	
	
	sort(arr.begin(), arr.end());
	// 정렬 후, end가 가장 앞선거부터 쭈욱...넣는데, 만약 겹치면 out

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