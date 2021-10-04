#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int width, height;
	vector<vector<char>> vChessBoard;
	cin >> width >> height;

	vChessBoard.resize(width, vector<char>(height, 0));

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			char tmp;
			cin >> tmp;
			vChessBoard[i][j] = tmp;
		}
	}

	int reDraw = 0;

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if ((i+j) % 2 == 0)	// Â¦¼ö
			{
				if (vChessBoard[i][j] == 'B')
				{
					reDraw++;
				}
			}
			else
			{
				if (vChessBoard[i][j] == 'W')
				{
					reDraw++;
				}
			}
		}
	}
	
	cout << reDraw;

	return 0;
}