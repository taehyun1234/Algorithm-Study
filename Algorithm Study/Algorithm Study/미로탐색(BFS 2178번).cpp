#include <iostream>
using namespace std;
#define MAX_ROW 100
#define MAX_COL 100

//https://cocoon1787.tistory.com/115 BFS이론부터 다시 싹 공부해볼 것.

int map[MAX_ROW][MAX_COL] = { 0, };
int visit[MAX_ROW][MAX_COL];

void BFS(int x,int y);

int main()
{
	int row, col;
	
	cin >> row >> col;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int tmp;
			cin >> tmp;
			map[i][j] = tmp;
		}
	}

	BFS(0, 0);

	return 0;
}

void BFS(int x, int y)
{

}