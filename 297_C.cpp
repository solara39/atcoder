#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;

	vector<string> S(H);
	for (int i = 0; i < H; i++)
		cin >> S[i];

	for (int i = 0; i < H; i++)
	{
		for (int j = 1; j < W; j++)
		{
			if (S[i][j - 1] == 'T' && S[i][j] == 'T')
			{
				S[i][j - 1] = 'P';
				S[i][j] = 'C';
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		cout << S[i] << endl;
	}
	return 0;
}
