#include<iostream>
#include<string>
using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;

	int matrix[110][110];
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> matrix[i][j];
	
	string S[H];
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (!matrix[i][j])
			{
				S[i] += ".";
			}
			else
			{
				S[i] += matrix[i][j] + 64;
			}
		}
	}
	for (int i = 0; i < H; i ++)
	{
		cout << S[i] << endl;
	}
}
