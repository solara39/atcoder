#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int R, C;
	cin >> R >> C;

	//string matrix[21][21];
	vector<vector<char> > matrix(R, vector<char>(C));
	//string res[21][21];
	vector<vector<char> > res(R, vector<char>(C));
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> matrix[i][j];
			res[i][j] = matrix[i][j];
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (matrix[i][j] >= '1' && matrix[i][j] <= '9')
			{
				for (int a = 0; a < R; a++)
				{
					for (int b = 0; b < C; b++)
					{
						if (abs(i - a) + abs(j - b) <= matrix[i][j] - '0')
							res[a][b] = '.';
					}
				}
			}
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << res[i][j];
		}
		cout << endl;
	}
	return 0;
}
