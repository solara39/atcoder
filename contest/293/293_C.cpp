#include<iostream>

using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;

	int A[H][W] = {0};
	for (int i = 1; i <= H; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			cin >> A[i][j];
		}
	}


}
